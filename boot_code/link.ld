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
__DYNAMIC  =  0;

MEMORY
{
  ROM         : ORIGIN = 0x1A000000, LENGTH = 0x2000
  L2          : ORIGIN = 0x1C000000, LENGTH = 0x4000
}

/* We have to align each sector to word boundaries as our current s19->slm
 * conversion scripts are not able to handle non-word aligned sections. */

SECTIONS
{

    .text : {
	. = ALIGN(4);
	KEEP(*(.vectors))
	_stext = .;
	*(.text)
	*(.text.*)
	_etext  =  .;
	*(.lit)
	*(.shdata)
	*(.boot)
	*(.boot.data)
	*(.rodata);
	*(.rodata.*)
	*(.eh_frame*)
	*(.data);
	*(.data.*)
	*(.bss)
	*(.bss.*)
	*(.sbss)
	*(.sbss.*)
	*(COMMON)
	. = ALIGN(4);
	_bss_start = .;
	. = ALIGN(4);
	_bss_end = .;
	*(.boot)
	*(.boot.data)
	_endtext = .;
    }  > ROM

     .heapl2ram :
     {
	*(.ram)
	*(.heapl2ram)
     } > L2

     .stack :
     {
	. = ALIGN(4);
       stack = . + 1024;
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
