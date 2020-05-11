#!/usr/bin/env python3
import pandas
# import pprint
from pandas import DataFrame
import argparse
import sys
from os import path

parser = argparse.ArgumentParser(
    prog='pulp_gen_table.py',
    description="""Generate latex tables for the PULP documentation""")

parser.add_argument('filename', type=str, help='XLSX file to parse')

parser.add_argument('-b,', '--base-address', type=str, default="0x00000000",
                    help="""Assume that the registers of the IP are relative to the given base address.
                    Must be in hexadecimal notation. Default is 0x00000000""")
parser.add_argument('-n,', '--name', type=str, default="UNNAMED",
                    help="""Give the IP a name. Default is UNNAMED.""")
parser.add_argument('-o,', '--output', type=str,
                    help="""Write to file instead of
                    stdout""")
parser.add_argument('--dump-required-macros', action='store_true',
                    help="""Print the required latex macros to be able to use
                    the output of this tool""")
parser.add_argument('--verbose', action='store_true',
                    help='Show more information about commands')

args = parser.parse_args()


def escape_latex(s):
    """ Escape characters that are special in latex
    http://stackoverflow.com/a/16264094/2570866"""
    CHARS = {
        '&':  r'\&',
        '%':  r'\%',
        '$':  r'\$',
        '#':  r'\#',
        '_':  r'\_',
        '{':  r'\{',
        '}':  r'\}',
        '~':  r'\~',
        '^':  r'\^',
        '\\': r'\\\\',
        '\n': r'\\',  # try to preserve newlines
    }

    return ("".join([CHARS.get(char, char) for char in s]))


def parse_yaml(file_name):
    """Parse yaml IP documentation format into internal representation suitable for
    generating documentation."""
    pass


def parse_excel(file_name):
    """Parse legacy IP documentation excel sheets into internal representation
    suitable for generating documentation."""
    xls = pandas.ExcelFile(file_name)
    sheets = pandas.read_excel(xls, None)

    # for k, v in sheets.items():
    #     print(k)

    expected_reglist_keys = ['Address', 'Default Value', 'Description',
                             'Host Access Type', 'Register Name',
                             'Register Type', 'Size']

    expected_regmap_keys = ['Bit Position', 'Bit field', 'Description',
                            'Host Access Type', 'Register', 'Reset Value',
                            'Size']
    try:
        reglist = sheets['IPREGLIST_rel1.0.0']
        regmap = sheets['IPREGMAP_rel1.0.0']
    except KeyError as e:
        print('parse_excel: sheet ' + str(e) + ' does not exist in ' +
              file_name, file=sys.stderr)
        exit(-1)

    # sanity checks on sheets
    for expected in expected_reglist_keys:
        if not (expected in reglist):
            print('parse_excel: reglist is missing key ' + expected,
                  file=sys.stderr)
            exit(-1)

    for expected in expected_regmap_keys:
        if not (expected in regmap):
            print('parse_excel: regmap is missing key/column ' + expected,
                  file=sys.stderr)
            exit(-1)

    # aggresively remove empty rows (marked with nan)
    regmap_na_free = regmap.dropna(axis=0, how='any')
    # show dropped rows
    if args.verbose:
        print("parse_excel: Dropped the following rows", file=sys.stderr)
        print(regmap[~regmap.index.isin(regmap_na_free.index)],
              file=sys.stderr)
    regmap = regmap_na_free

    # Deleting rows makes holes in the index. Refresh the index.
    regmap = regmap.reset_index(drop=True)

    reglist_dict = DataFrame.to_dict(reglist)
    regmap_dict = DataFrame.to_dict(regmap)

    # group by register name
    regmap_normalized = {}
    size = len(regmap_dict['Register'])
    for i in range(size):
        # take register name as key for new dict
        key = escape_latex(regmap_dict['Register'][i])
        # the values are the associated bit fields plus information
        value = {}
        value['Bit field'] = escape_latex(regmap_dict['Bit field'][i])
        value['Bit Position'] = int(regmap_dict['Bit Position'][i])
        value['Size'] = int(regmap_dict['Size'][i])
        value['Host Access Type'] = regmap_dict['Host Access Type'][i]
        value['Reset Value'] = regmap_dict['Reset Value'][i]
        value['Description'] = escape_latex(regmap_dict['Description'][i])

        if key in regmap_normalized:
            regmap_normalized[key].append(value)
        else:
            regmap_normalized[key] = [value]

    # now we make sure that each registers bitfield list are sorted according
    # to their bit positions in descending order
    regmap_tmp = {}
    for regname, bitfields in regmap_normalized.items():
        regmap_tmp[regname] = sorted(bitfields,
                                     reverse=True,
                                     key=lambda field: field['Bit Position'])

    regmap_normalized = regmap_tmp

    reglist_tmp = reglist.set_index('Register Name',
                                    verify_integrity=True).T.to_dict()

    # sort register by ascending address (so that we have a nice ordered table)
    # the addresses are strings so we need to hack around a bit
    reglist_normalized = sorted(reglist_tmp.items(),
                                key=lambda item: int(item[1]['Address'], 16))
    # normalize names
    reglist_normalized = list(map(lambda e: (escape_latex(e[0]), e[1]),
                                  reglist_normalized))
    # pprint.pprint(reglist_normalized)

    # reglist_normalized is now a list of tuples, where the first entry is the
    # register name and the second entry a dictionary with its properties such
    # as address, reset value etc.

    # regmap_normalized is now a dictionary where the keys are the register
    # name and the values are lists of its bitfields, ordered by descending
    # position of the fields. Actually we should also make this a lists instead
    # because dictionary don't preserve the insertion order before python 3.6,
    # but we don't care for now
    return (reglist_normalized, regmap_normalized)


def write_bitbox(bitfields, start, length, downsize=True):
    """Write a bitbox latex sequency consuming length bits from bitfield. Return
    the remaining bitfield. If downsize is true, then try to shrink text to fit
    into smaller boxes

    """

    bitbox = ""
    # gray box string
    reserved = "\\color{lightgray}\\rule{\\width}{\\height}"

    # remaining bitfields to be processed after this calls returns
    remaining = []

    # keep track of the current bits we are handling. Using it we can spot
    # reserved/empty spaces and fill them with a gray box
    index = start
    # generation of bitboxes
    stop = start - length
    for bf in bitfields:
        name = bf['Bit field']
        position = bf['Bit Position']
        size = bf['Size']

        if downsize and size <= 2 and len(name) <= 3:
            name = "\\tiny " + name
        elif downsize and size <= 2 and len(name) > 3:
            name = r'\let\bw=\width\resizebox{\bw}{!}' + ('{~%s~}' % name)

        if position > index:
            print("""write_bitbox: field %s starts (%d) and ends (%d) outside
            above assigned range (start=%d, length=%d). This means the input
            data is most likely buggy.""" %
                  (name, position, (position + size), start, length),
                  file=sys.stderr)
            exit(-1)

        # truncate if field is too long. This happens if we try to output the
        # lower 16 bit of a 32-bit field
        if position + size > index:
            size = start - position

        # index and position disagree so we insert a gray box
        if (position + size < index) and (position + size > stop):
            bitbox += (" \\bitbox{%s}{%s}" %
                       (index - max(position + size, stop), reserved))
            index = max(position + size, stop)

        # adjust size so that we don't underflow
        if (position + size > stop):
            index = index - size
            size = min(size, position + size - stop)
            bitbox += (" \\bitbox{%s}{%s}" % (size, name))

        # we can't fully process these bitfields, save them
        if position < stop:
            remaining.append(bf)

    # fill the remaining bits with gray boxes
    if index > stop:
        bitbox += (" \\bitbox{%s}{%s}" % (index-stop, reserved))

    return (remaining, bitbox)


def write_reg_item(bitfield):
    """Write a single reg item description.
    Like this
    \regitem{Bit 15-0}{MF}{R}{Current DCO multiplication factor value bitfield}
    """
    size = bitfield['Size']
    position = bitfield['Bit Position']
    bitrange = "RANGE ERROR"
    if size == 1:
        bitrange = "Bit %d" % position
    else:
        bitrange = "Bit %d - %d" % (position + size - 1, position)

    name = bitfield['Bit field']
    access = bitfield['Host Access Type']
    description = bitfield['Description']
    return ("\\regitem{%s}{%s}{%s}{%s}" %
            (bitrange, name, access, description))


def write_reg_doc(regname, bitfields, address=0, reset_value=0):
    """Write register documentation in latex to stream. Generates 32-bit register
    overview split into 2 x 16-bit slices."""

    remaining, upper_bitbox = write_bitbox(bitfields, 32, 16)
    _, lower_bitbox = write_bitbox(remaining, 16, 16)

    reg_items = ""
    for bf in bitfields:
        reg_items += ('  ' + write_reg_item(bf) + '\n')
    reg_items = reg_items[:-1]

    print("""
\\regdoc{0x%08X}{0x%08X}{%s}{
  \\begin{bytefield}[endianness=big,bitwidth=2em]{16}
    \\bitheader[lsb=16]{16-31} \\\\
   %s \\\\[3ex]
    \\bitheader{0-15} \\\\
   %s
  \\end{bytefield}
}{
%s
}
""" % (address, reset_value, regname,
       upper_bitbox, lower_bitbox, reg_items))

    # for k, v in upper_reg.items():
    #     lower_bitbox += (" \\bitbox{%s}{%s}" % (size, fieldname))


def write_reg_entry(reg_entry, base_address=0):
    name, attrs = reg_entry
    address = '0x%08X' % ((int(attrs['Address'], 16) + base_address))
    reset = '0x%08X' % int(attrs['Default Value'], 16)
    reg_type = attrs['Register Type']
    size = str(attrs['Size'])
    access = attrs['Host Access Type']
    description = escape_latex(attrs['Description'])

    return ("%s & \\texttt{%s} & %s & %s & %s & \\texttt{%s} & %s\\\\"
            % (name, address, size, reg_type, access, reset, description))


def write_reg_table(reglist, table_name="NO NAME", base_address=0):
    """Write register overview table in latex to stream."""
    regs = ""
    for reg in reglist:
        regs += '  ' + write_reg_entry(reg, base_address) + '\n'
        regs += '  \\hline\n'
    regs = regs[:-1]

    # Understand that there is a reason this looks like this. The output is
    # good.
    print("""
\\subsection{%s Registers}
{\\small
\\begin{tabularx}{\\textwidth}{|l|l|l|l|l|l|X|}
  \\hline
  \\textbf{Name} & \\textbf{Address}  & \\textbf{Size} & \\textbf{Type} & \\textbf{Access} & \\textbf{Default} & \\textbf{Description} \\\\
  \\hline
%s
  \\caption{%s}
\\end{tabularx}
}
""" % (table_name, regs, table_name))
    return


required_macros = r"""
%
% Make also sure you use the ltablex package to split tables that are too long
%
\newcommand{\regdoc}[5]{
  \subsection{#3}
  \textbf{Address:} \texttt{#1}\\%
  \textbf{Reset Value:} \texttt{#2}\\%
  \begin{center}
    #4
  \end{center}
  \begin{enumerate}[leftmargin=20mm]
    #5
  \end{enumerate}
}

\newcommand\regitem[4]{%
  \item[\texttt{#1}] \textbf{#2} \textit{(#3)} #4
}
"""
if __name__ == "__main__":

    if args.dump_required_macros:
        print(required_macros)
        exit(0)

    # redirect to stdout to file if desired
    sys.stdout = open(args.output, "w") if args.output else sys.stdout

    if not(path.exists(args.filename)):
        print("pulp_gen_table.py: File " + args.filename + " does not exist.",
              file=sys.stderr)
        exit(-1)
    (reglist, regmap) = parse_excel(args.filename)

    base_address = int(args.base_address, 16)
    write_reg_table(reglist, escape_latex(args.name), base_address)

    for regname, bitfields in regmap.items():
        address = 0
        reset = 0
        # look up address and default value for register from reglist
        for reg in reglist:
            name, attrs = reg
            if name == regname:
                address = int(attrs['Address'], 16)
                reset = int(attrs['Default Value'], 16)

        # generate
        write_reg_doc(regname, bitfields, address + base_address, reset)

    if args.output:
        sys.stdout.close()
