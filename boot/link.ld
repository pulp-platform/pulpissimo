/*
* Copyright 2020 ETH Zurich
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


/* not needed, but we need separate linker scripts anyway */
OUTPUT_ARCH(riscv)
SEARCH_DIR(.)

MEMORY
{
  ROM (rx)    : ORIGIN = 0x1A000000, LENGTH = 0x2000
  L2  (!rx)   : ORIGIN = 0x1C000004, LENGTH = 0x4000
}

/* We have to align each sector to word boundaries as our current s19->slm
 * conversion scripts are not able to handle non-word aligned sections. */

SECTIONS
{

  __stack_size = DEFINED(__stack_size) ? __stack_size : 0x800;

  .text :
   {
     . = ALIGN(4);
     __vector_start = .;
     KEEP(*(.vectors))
     _stext = .;
     *(.text)
     *(.text.*)
     _etext  =  .;
     *(.boot)
     *(.eh_frame*)
     _endtext = .;
  }  > ROM

  .rodata : ALIGN(4)
    {
     *(.rodata);
     *(.rodata.*)
    } > ROM

  .data : ALIGN(4)
  {
    sdata  =  .;
    _sdata  =  .;
    __data_begin = .;
    *(.boot.data)
    *(.data_fc)
    *(.data_fc.*)
    *(.data);
    *(.data.*)
    __sdata_begin = .;
    *(.sdata);
    *(.sdata.*)
    *(.sdata2.*)
    . = ALIGN(4);
    edata  =  .;
    _edata  =  .; /* man 3 end: first addr after data */
  } > L2

  /* uninitialized variables to reduce startup time */
  .noinit : ALIGN(4)
    {
      *(.noinit)
    } > L2

  .bss : ALIGN(8)
    {
      _bss_start = .;
      __bss_start = .;
      *(.shbss) /* don't even know where this is from */
      *(.bss)
      *(.bss.*)
      *(.sbss)
      *(.sbss.*)
      *(COMMON)
      . = ALIGN(4);
      __bss_end = .;
      _bss_end = .;
      _end = .; /* man 3 end: first addr after bss */
    } > L2

  /* The compiler uses this to access data in the .sdata, .data, .sbss and .bss
     sections with fewer instructions (relaxation). This reduces code size. */
    PROVIDE(__global_pointer$ = MIN(__sdata_begin + 0x800,
			    MAX(__data_begin + 0x800, __bss_end - 0x800)));

  .stack :
    {
      . = ALIGN(16);
      __stack_bottom = .;
      . += __stack_size;
      __stack_top = .;
    } > L2


  .stab  0 (NOLOAD) :
    {
      [ .stab ]
    }

  .stabstr  0 (NOLOAD) :
    {
      [ .stabstr ]
    }
}
