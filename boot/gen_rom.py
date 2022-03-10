#!/usr/bin/env python3

from string import Template
import argparse
import os.path
import sys


parser = argparse.ArgumentParser(description='Convert binary file to verilog rom')
parser.add_argument('filename', metavar='filename', type=str,
                    help='filename of input binary')
parser.add_argument('--title', '-t', type=str, required=True)
parser.add_argument('outname', metavar='outname', type=str,
                    help='filename of output SystemVerilog module')

args = parser.parse_args()
file = args.filename

# check that file exists
if not os.path.isfile(file):
    print("File {} does not exist.".format(args.filename))
    sys.exit(1)

filename = os.path.splitext(file)[0]

license = """\
//-----------------------------------------------------------------------------
// Title         : $title
//-----------------------------------------------------------------------------
// File          : $file_name
//-----------------------------------------------------------------------------
// Description :
// Auto-generated bootrom from gen_bootrom.py
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2021 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------

// Auto-generated code
"""

module = """\
module $module_name #(
    parameter ADDR_WIDTH=32,
    parameter DATA_WIDTH=32
) (
   input logic                   CLK,
   input logic                   CEN,
   input logic  [ADDR_WIDTH-1:0] A,
   output logic [DATA_WIDTH-1:0] Q
);

    localparam   NUM_WORDS = 2**ADDR_WIDTH;
    logic [ADDR_WIDTH-1:0] A_Q;

    const logic [NUM_WORDS-1:0][DATA_WIDTH-1:0] MEM = {
$content
    };

    always_ff @(posedge CLK)
    begin
      if (CEN == 1'b0)
        A_Q <= A;
    end

    assign Q = MEM[A_Q];

endmodule
"""


def read_bin():
    with open(filename + ".cde", 'r') as f:
        rom = f.readlines()
        rom = [x.strip() for x in rom]
    return rom


rom = read_bin()


""" Generate SystemVerilog bootcode for FPGA
"""
with open(args.outname, "w") as f:
    rom_str = ""
    # process in junks of 32 bit (4 byte)
    for data in reversed(rom):
        rom_str += "        32'b" + data + ",\n"

    # remove the trailing comma
    rom_str = rom_str[:-2]

    l = Template(license)
    f.write(l.substitute(title=args.title, file_name=args.outname))

    s = Template(module)
    sv_module = os.path.splitext(args.outname)[0]
    f.write(s.substitute(module_name=sv_module, content=rom_str))

f.close()
