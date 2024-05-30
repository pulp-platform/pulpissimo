# PULPissimo on the Digilent Nexys Boards
[\[Documentation Nexys 4\]](https://reference.digilentinc.com/reference/programmable-logic/nexys-4/reference-manual)
[\[Documentation Nexys 4 DDR\]](https://reference.digilentinc.com/reference/programmable-logic/nexys-4-ddr/reference-manual)
[\[Documentation Nexys A7 (50T/100T)\]](https://reference.digilentinc.com/reference/programmable-logic/nexys-a7/reference-manual)

## Board revisions
The nexys board had 3 revisions in the past years. Following minor changes have been made according to the reference manual:
### Nexys 4 -> Nexys 4DDR
- replacement of the Cellular RAM with a DDR2 SDRAM
- new pin-out of the FPGA banks

Thus Nexys 4 need a different constraint file, while the Nexys 4 DDR board and both versions of Nexys A7 board can share the same file.

### Nexys 4 DDR -> Nexys A7
- rebrand only
- additional board with smaller FPGA

## Bitstream Generation
The Makefile can handle all revisions of the Nexys board. You can generate the Bitfile for the desired revision by running
```Shell
make nexys rev=[nexys4|nexys4DDR|nexysA7-50T|nexysA7-100T]
```
in the `fpga` folder. The generated bitstream will be copied into the fpga folder.

## Bitstream Download
To download this bitstream into the FPGA connect the PROG USB header, turn the board on and run
```Shell
make -C pulpissimo-nexys download
```

## Default SoC and Core Frequencies

By default the clock generating IPs are synthesized to provide the following frequencies to PULPissimo:

| Clock Domain   | Default Frequency on Nexys 4 board |
|----------------|----------------------------------------|
| Core Frequency | 10 MHz                                 |
| SoC Frequency  |  5 MHz                                 |


## Peripherals
PULPissimo is connected to the following board peripherals:


| PULPissimo Pin | Mapped Board Peripheral                             |
|----------------|-----------------------------------------------------|
| `SPIM0`        | PMOD C Pins 1-8                                          |
| `SDIO` 	     | SD Card Memory                                      |
| `I2C` 	     | PMOD B Pins 1,2                                     |
| `I2S` 	     | PMOD B Pins 7-10                                    |
| `JTAG` 	     | PMOD A Pins 1-4                                     |
| `spim_csn1`    | LED0                                                |
| `cam_pclk`     | LED1                                                |
| `cam_hsync`    | LED2                                                |
| `cam_data0`    | LED3                                                |
| `cam_data1`    | Switch 0                                            |
| `cam_data2`    | Switch 1                                            |
| `cam_data3`    | Button C                                            |
| `cam_data4`    | Button D                                            |
| `cam_data5`    | Button L                                            |
| `cam_data6`    | Button R                                            |
| `cam_data7`    | Button U                                            |

For more information consult board constraint files.

### UART
PULPissimo's UART port is mapped to the onboard FTDI FT2232HQ USB-UART bridge and thus accessible through the UART micro-USB connector (J6).

### QSPI-Flash
Nexys boards have a Spansion S25FL128S Flash memory which can be used for configuration of the FPGA. It also can be used for user applications. Almost all Flash pins are connected on the standard IO Banks except for the SCK input. SCK is a special Configuration I/O pin and can therefore only connected via the Primitive STARTUPE2 and its USRCCLKO input. (See commented section in xillinx_pulpissimo.sv of the nexys port)

As the IOBUFs of each pulpissimo output through the padframe cannot drive signals connected to other prmitives an extended modification would be nessecary. Therefore the QSPI-Flash is not implemented in this version.

### Reset Button
The CPU RESET button (G4) resets the RISC-V CPU.

### JTAG
Although the Nexys board has an on-board JTAG programmer, it is not possible to connect it to the PULPissimo JTAG port.
Therefore you need an external JTAG programmer device connected to PMOD A. The pinout is as follow:

| JTAG Signal | PMOD Pin |
|-------------|----------|
| TMS         | JA1      |
| TDI         | JA2      |
| TDO         | JA3      |
| TCK         | JA4      |
| GND         | JA5      |
| VCC (trgt)  | JA6      |

The directory holding this README contains a OpenOCD configuration file for a tested adapter.
The commands below are to be executed from within the `fpga` directory.

#### Digilent HS-2

If you have Vivado running remember to disconnect the target and close HW Manager before attempting to use OpenOCD.


```Shell
$OPENOCD/bin/openocd -f pulpissimo-nexys4/openocd-nexys-hs2.cfg
```

