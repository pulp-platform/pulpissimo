# PULPissimo on the Xilinx ZCU102 Board
[\[Datasheet\]](https://www.xilinx.com/support/documentation/boards_and_kits/zcu102/ug1182-zcu102-eval-bd.pdf)

## Bitstream Generation
In the `fpga` folder, run
```Shell
make zcu102
```
which will generate `pulpissimo_zcu102.bit`.


## Bitstream Download
To download this bitstream into the FPGA connect the PROG USB header, turn the board on and run
```Shell
make -C pulpissimo-zedboard download
```

## Default SoC and Core Frequencies

By default the clock generating IPs are synthesized to provide the following frequencies to PULPissimo:

| Clock Domain   | Default Frequency on ZCU102 board  |
|----------------|------------------------------------|
| Core Frequency | 20 MHz                             |
| SoC Frequency  | 10 MHz                             |


## Peripherals
Most peripherals of are connected to the ARM processing system domain of the SoC and cannot be used from the programmable logic domain.
The peripherals available to PULPissimo are thus very limited.

### Reset Button
The CPU RESET button (SW20) resets the RISC-V CPU.

### UART
PULPissimo's UART port is mapped to Channel 2 of the CP2108 chip.
When connecting the board to a computer using the USB/JTAG/UART micro-USB connector (J83), it is the last of the four detected serial devices.

### JTAG
A Digilent JTAG-HS2 adapter is used to connect the RISC-V debug module from the 
GPIO port (PMOD0 header) of the board to the host.

| JTAG Signal | FPGA Port | J55 Pin  |
|-------------|-----------|----------|
| tms         | PMOD0_0   | Pin 1    |
| tdi         | PMOD0_1   | Pin 3    |
| tdo         | PMOD0_2   | Pin 5    |
| tck         | PMOD0_3   | Pin 7    |
| gnd         | GND       | Pin 9    |
| vdd         | 3V3       | Pin 11   |

An OpenOCD configuration file for the Digilent JTAG-HS2 adapter is included.
To use it, run

```Shell
$OPENOCD/bin/openocd -f ~/pulpissimo/fpga/pulpissimo-zcu102/openocd-zcu102-digilent-jtag-hs2.cfg
```
