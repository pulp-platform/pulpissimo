# PULPissimo on the ZedBoard
[\[Documentation\]](http://zedboard.org/product/zedboard)

## Bitstream Generation
In the `fpga` folder, run
```Shell
make zedboard
```
which will generate `pulpissimo_zedboard.bit`.

## Bitstream Download
To download this bitstream into the FPGA connect the PROG USB header, turn the board on and run
```Shell
make -C pulpissimo-zedboard download
```

## Default Frequencies

By default the clock generating IPs are synthesized from the 100 MHz input (IC17 via Y9) to provide the following frequencies to PULPissimo.
The SoC Frequency is fed into all peripherals as `periph_clk_i`.

| Clock Domain   | Frequency |
|----------------|-----------|
| Core Frequency | 20 MHz    |
| SoC Frequency  | 10 MHz    |


## Peripherals
If in doubt please review constraint file for current peripheral mapping in `constraints/zedboard.xdc`.

### Reset Button
The BTNC is connected as reset button.

### JTAG
Since there is no way of connecting the RISC-V core to the on-board FTDI USB JTAG programmer you have to attach an external device PMOD A to do so.

| JTAG Signal | PMOD Pin |
|-------------|----------|
| TMS         | JA1      |
| TDI         | JA2      |
| TDO         | JA3      |
| TCK         | JA4      |
| GND         | JA5      |
| VCC (trgt)  | JA6      |

The directory holding this README contains OpenOCD configuration files for some known-working adapters.
The commands below are to be executed from within the `fpga` directory.

#### Digilent HS-2

The HS-2 uses the same FTDI chip as the ZedBoard's JTAG port.
So to make it work change the serial number in provided
`openocd-zedboard-hs2.cfg` if you want to have it connected simultaneously with ZedBoard. If you have
Vivado running remember to disconnect the target and close HW Manager before attempting to use OpenOCD.
Otherwise there will be an error about target being busy.

```Shell
$OPENOCD/bin/openocd -f pulpissimo-zedboard/openocd-zedboard-hs2.cfg
```

#### Altera USB Blaster

After connecting the adapter with 6 jumper wires, simply run:

```Shell
$OPENOCD/bin/openocd -f pulpissimo-zedboard/openocd-zedboard-usbblaster.cfg
```

### UART

There are UART pins connected to the same PMOD as the JTAG signals (PMOD A), which are utilized by the stdio driver of the PULP SDK (e.g., for the hello example).
The following list depicts the signals (from the FPGA's point of view).

| UART Signal | PMOD Pin |
|-------------|----------|
| RXD         | JA7      |
| TXD         | JA8      |
| RTS         | JA9      |
| CTS         | JA10     |
| GND         | JA11     |

### I2C

Two pairs of I2C signals are available on PMOD B:

| Signal    | PMOD Pin |
|-----------|----------|
| I2C0_SCL  | JB1      |
| I2C0_SDA  | JB2      |
| I2C1_SCL  | JB3      |
| I2C1_SDA  | JB4      |
