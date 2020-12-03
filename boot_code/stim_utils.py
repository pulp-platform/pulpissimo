#!/usr/bin/env python3

#
# Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
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
#

from elftools.elf.elffile import ELFFile
import os
import os.path
import struct
import argparse



class stim(object):


  def __init__(self, verbose=False):
    self.binaries = []
    self.mem = {}
    self.verbose = verbose
    self.areas = []

    self.dump('Created stimuli generator')

  def get_entry(self):
    with open(self.binaries[0], 'rb') as file:
        elffile = ELFFile(file)
        return elffile.header['e_entry']

  def dump(self, str):
    if self.verbose:
      print (str)

  def add_binary(self, binary):
    self.dump('  Added binary: %s' % binary)
    self.binaries.append(binary)

  def add_area(self, start, size):
    self.dump('  Added target area: [0x%x -> 0x%x]' % (start, start + size))
    self.areas.append([start, start+size])


  def __add_mem_word(self, base, size, data, width):

    aligned_base = base & ~(width - 1)

    shift = base - aligned_base
    iter_size = width - shift
    if iter_size > size:
      iter_size = size

    value = self.mem.get(str(aligned_base))
    if value is None:
      value = 0

    value &= ~(((1<<width) - 1) << (shift*8))
    value |= int.from_bytes(data[0:iter_size], byteorder='little') << (shift*8)

    self.mem[str(aligned_base)] = value

    return iter_size





  def __add_mem(self, base, size, data, width):

    while size > 0:

      iter_size = self.__add_mem_word(base, size, data, width)

      size -= iter_size
      base += iter_size
      data = data[iter_size:]


  def __gen_stim_slm(self, filename, width):

    self.dump('  Generating to file: ' + filename)

    try:
      os.makedirs(os.path.dirname(filename))
    except:
      pass

    with open(filename, 'w') as file:
      for key in sorted(self.mem.keys()):
        file.write('%X_%0*X\n' % (int(key), width*2, self.mem.get(key)))

  def __parse_binaries(self, width):

    self.mem = {}

    for binary in self.binaries:

        with open(binary, 'rb') as file:
            elffile = ELFFile(file)

            for segment in elffile.iter_segments():

                if segment['p_type'] == 'PT_LOAD':

                    data = segment.data()
                    addr = segment['p_paddr']
                    size = len(data)

                    load = True
                    if len(self.areas) != 0:
                      load = False
                      for area in self.areas:
                        if addr >= area[0] and addr + size <= area[1]:
                          load = True
                          break

                    if load:

                      self.dump('  Handling section (base: 0x%x, size: 0x%x)' % (addr, size))

                      self.__add_mem(addr, size, data, width)

                      if segment['p_filesz'] < segment['p_memsz']:
                          addr = segment['p_paddr'] + segment['p_filesz']
                          size = segment['p_memsz'] - segment['p_filesz']
                          self.dump('  Init section to 0 (base: 0x%x, size: 0x%x)' % (addr, size))
                          self.__add_mem(addr, size, [0] * size, width)

                    else:

                      self.dump('  Bypassing section (base: 0x%x, size: 0x%x)' % (addr, size))




  def gen_stim_slm_64(self, stim_file):

    self.__parse_binaries(8)

    self.__gen_stim_slm(stim_file, 8)


  def gen_stim_bin(self, stim_file):

    self.__parse_binaries(1)

    try:
      os.makedirs(os.path.dirname(stim_file))
    except:
      pass

    with open(stim_file, 'wb') as file:
      prev_addr = None
      for key in sorted(self.mem.keys()):
        addr = int(key)
        if prev_addr is not None:
          while prev_addr != addr - 1:
            file.write(struct.pack('B', 0))
            prev_addr += 1

        prev_addr = addr
        file.write(struct.pack('B', int(self.mem.get(key))))



if __name__ == "__main__":
  parser = argparse.ArgumentParser(description='Generate stimuli')

  parser.add_argument("--binary", dest="binary", default=None, help="Specify input binary")
  parser.add_argument("--vectors", dest="vectors", default=None, help="Specify output vectors file")
  parser.add_argument("--stim-bin", dest="stim_bin", default=None, help="Generate binary stimuli")
  parser.add_argument("--area", dest="areas", action="append", help="Specify stimuli area")

  args = parser.parse_args()

  if args.binary is None:
    raise Exception('Specify the input binary with --binary=<path>')

  stim_gen = stim(verbose=True)

  stim_gen.add_binary(args.binary)

  for area in args.areas:
    start, size = area.split(':')
    stim_gen.add_area(int(start, 0), int(size, 0))

  if args.vectors is not None:
    stim_gen.gen_stim_slm_64(args.vectors)

  if args.stim_bin is not None:
    stim_gen.gen_stim_bin(args.stim_bin)
