# PULPissimo on the Xilinx ZCU106 Board
[\[Datasheet\]](https://www.xilinx.com/support/documents/boards_and_kits/zcu106/ug1244-zcu106-eval-bd.pdf)

## Bitstream Generation
In the `fpga` folder, run
```Shell
make zcu106
```
which will generate `pulpissimo_zcu106.bit`.

## Bitstream Download
To download this bitstream into the FPGA connect the PROG USB header, turn the board on and run
```Shell
make -C pulpissimo-zedboard download
```

## Default SoC and Core Frequencies

By default the clock generating IPs are synthesized to provide the following frequencies to PULPissimo:

| Clock Domain   | Default Frequency on ZCU106 board  |
|----------------|------------------------------------|
| Core Frequency | 20   MHz                           |
| SoC Frequency  | 13.3 MHz                           |


## Peripherals
Most peripherals of are connected to the ARM processing system domain of the SoC and cannot be used from the programmable logic domain.
The peripherals available to PULPissimo are thus very limited.

### Reset Button
The center button is used to trigger the reset (SW15).

### UART
PULPissimo's UART port is mapped to Channel 2 of the Silicon Labs CP2108 chip.
When connecting the board to a computer using the USB/JTAG/UART micro-USB connector, it is the last of the four detected serial devices.

### JTAG
Unfortunately, only one channel of the Silicon Labs CP2108 chip is connected to the programmable logic domain.
Since we are using that channel for UART, the micro-USB connector on the board cannot be used to communicate with the RISC-V debug module over JTAG.
Instead, you need to connect a separate JTAG adapter to the GPIO port (PMOD1 header) of the board:

| JTAG Signal | FPGA Port | J87 Pin  |
|-------------|-----------|----------|
| tms         | PMOD1_0   | Pin 1    |
| tdi         | PMOD1_1   | Pin 3    |
| tdo         | PMOD1_2   | Pin 5    |
| tck         | PMOD1_3   | Pin 7    |
| gnd         | GND       | Pin 9    |
| vdd         | 3V3       | Pin 11   |

An OpenOCD configuration file for the Digilent JTAG-HS2 adapter is included. As the same FTDI chip is used, make sure to change the serial number in there to point to the correct chip.
To use it, run

```Shell
$OPENOCD/bin/openocd -f pulpissimo/home/meggiman/projects/pulp/pulpissimo/fpga/pulpissimo-zcu106/openocd-zcu106.cfg
```
