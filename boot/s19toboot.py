#!/usr/bin/python

# Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves
# Technologies
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# ////////////////////////////////////////////////////////////////////////////////
# // Company:        Multitherman Laboratory @ DEIS - University of Bologna     //
# //                    Viale Risorgimento 2 40136                              //
# //                    Bologna - fax 0512093785 -                              //
# //                                                                            //
# // Engineer:       Davide Rossi - davide.rossi@unibo.it                       //
# //                                                                            //
# // Additional contributions by:                                               //
# //                 Andreas Traber - atraber@student.ethz.ch                   //
# //                 Michael Gautschi - gautschi@iis.ethz.ch                    //
# //                                                                            //
# // Create Date:    05/04/2013                                                 //
# // Design Name:    ULPSoC                                                     //
# // Project Name:   ULPSoC                                                     //
# // Language:       tcl, now python                                            //
# //                                                                            //
# // Description:    s19 to slm conversion tool for stxp70 cluster compilation  //
# //                                                                            //
# // Revision:                                                                  //
# // Revision v0.1 - File Created                                               //
# // Revision v0.2 - Modification: Compiler does now generate little endian     //
# //                 directly. revert bytes!                                    //
# // Revision v0.3 - Moved from 128 bit s19 to 8 bit s19 file. This solves our  //
# //                 problems with misaligned addresses in s19 files.           //
# // Revision v0.5 - Rewrote the whole thing in python to be consistent with    //
# //                 s19toslm                                                   //
# ////////////////////////////////////////////////////////////////////////////////

import sys
import math
import os


if(len(sys.argv) < 3):
    print "Usage s19toboot.py FILENAME OUT_FILENAME ARCHI"
    quit()


rom_size      = 1024 # in double words (64 bit)
rom_start     = 0x1A000000
rom_end       = rom_start + rom_size * 8 - 1

l2_size      = 128 # in double words (64 bit)
l2_start     = 0x1C02FE00
l2_end       = l2_start + l2_size * 8 - 1


###############################################################################
# Function to dump single bytes of a string to a file
###############################################################################
def dump_bytes( filetoprint, addr, data_s):
    for i in xrange(0,4,1):
        filetoprint.write("@%08X %s\n" % ( addr+i,  data_s[i*2:(i+1)*2] ))

###############################################################################
# Read s19 file and put data bytes into a dictionary
###############################################################################
def s19_parse(filename, s19_dict):
    s19_file = open(filename, 'r')
    for line in s19_file:
        rec_field = line[:2]
        prefix    = line[:4]

        if rec_field == "S0" or prefix == "S009" or prefix == "S505" or prefix == "S705" or prefix == "S017" or prefix == "S804" or line == "":
            continue

        data = line[-6:-4] # extract data byte
        str_addr = line[4:-6]

        addr = int("0x%s" % str_addr, 0)

        s19_dict[addr] = data

    s19_file.close()

###############################################################################
# arrange bytes in words
###############################################################################
def bytes_to_words(byte_dict, word_dict):
    for addr in byte_dict:
        wordaddr = addr >> 2
        data = "00000000"

        if wordaddr in word_dict:
            data = word_dict[wordaddr]

        byte = addr % 4
        byte0 = data[0:2]
        byte1 = data[2:4]
        byte2 = data[4:6]
        byte3 = data[6:8]
        new   = byte_dict[addr]

        if byte == 0:
            data = "%s%s%s%s" % (byte0, byte1, byte2, new)
        elif byte == 1:
            data = "%s%s%s%s" % (byte0, byte1, new,   byte3)
        elif byte == 2:
            data = "%s%s%s%s" % (byte0, new,   byte2, byte3)
        elif byte == 3:
            data = "%s%s%s%s" % (new,   byte1, byte2, byte3)

        word_dict[wordaddr] = data


s19_dict = {}
slm_dict = {}

s19_parse(sys.argv[1], s19_dict)
outfile = sys.argv[2]

archi = None
if len(sys.argv) > 3: archi = sys.argv[3]

# fill slm_dict with 0's
for wordaddr in xrange(rom_start >> 2, (rom_end>>2) + 1):
    slm_dict[wordaddr] = "00000000"

bytes_to_words(s19_dict, slm_dict)


# word align all addresses
rom_start   = rom_start   >> 2
rom_end     = rom_end     >> 2
l2_start    = l2_start   >> 2
l2_end      = l2_end     >> 2

###############################################################################
# open files
###############################################################################
rom_file  = open(outfile, 'w')
vlog_file = open("boot_code.sv",  'w')

# prepare file
vlog_file.write("""
module boot_code
(
    input  logic        CLK,
    input  logic        RSTN,

    input  logic        CSN,
    input  logic [8:0]  A,
    output logic [63:0] Q
  );

  const logic [63:0] mem[0:%d] = {
""" % (rom_size-1));

###############################################################################
# write the stimuli
###############################################################################
addr_last = rom_start - 1
for addr in sorted(slm_dict.keys()):
    data = slm_dict[addr]

    # rom address range
    if(addr >= rom_start and addr <= rom_end):
        rom_base = addr - rom_start
        rom_addr = (rom_base >> 1)

        # sanity check
        if addr != addr_last + 1:
            print "ERROR: Santiy check failed. Current addr {0:08X}, last addr {1:08X}".format(addr << 2, addr_last << 2)
        addr_last = addr

        is64 = archi != 'patronus'

        if is64:
            if((addr%2) == 0):
                data_even = data
            else:
                data_odd  = data
                if archi == 'GAP': rom_file.write("@%x %s%s\n" % ((addr & 0xffff) / 2, data_odd, data_even))
                elif archi in [ 'gap9', 'vega', 'wolfe', 'quentin', 'devchip', 'pulp', 'pulpissimo']:
                    rom_file.write("{0:032b}\n" .format(int('0x' + data_even, 16)))
                    rom_file.write("{0:032b}\n" .format(int('0x' + data_odd,  16)))
                    #rom_file.write("@%x %s\n" % ((addr & 0xffff)-1, data_even))
                    #rom_file.write("@%x %s\n" % ((addr & 0xffff), data_odd))
                elif archi == 'vivosoc3':
                    rom_file.write("@%x %s\n" % ((addr & 0xffff)-1, data_even))
                    rom_file.write("@%x %s\n" % ((addr & 0xffff), data_odd))
                else: rom_file.write("%s%s\n" % (data_odd, data_even))
                vlog_file.write("    64'h%s%s,\n" % (data_odd, data_even))
        else:
            if((addr%2) == 0):
                data_even = data
                rom_file.write("%s\n" % (data))
                vlog_file.write("    32'h%s,\n" % (data))
            else:
                data_odd  = data
                rom_file.write("%s\n" % (data))
                vlog_file.write("    32'h%s,\n" % (data))

# remove ,\n
vlog_file.seek(-2, os.SEEK_END)
vlog_file.write("""};

  logic [%d:0] A_Q;

  always_ff @(posedge CLK or negedge RSTN)
  begin
    if (~RSTN)
      A_Q <= '0;
    else
      if (~CSN)
        A_Q <= A;
  end

  assign Q = mem[A_Q];

endmodule""" % (math.log(rom_size, 2)));

###############################################################################
# close all files
###############################################################################
rom_file.close()
vlog_file.close()
