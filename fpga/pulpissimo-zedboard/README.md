# PULPissimo on the ZedBoard
[\[Documentation\]](http://zedboard.org/product/zedboard)

## Bitstream Generation
In the fpga folder, run
```Shell
make zedboard
```
which will generate `pulpissimo_zedboard.bit`.
Use Vivado to load it into the FPGA.

## Default SoC and Core Frequencies

By default the clock generating IPs are synthesized to provide the following frequencies to PULPissimo:

| Clock Domain   | Default Frequency on Nexys Video board |
|----------------|----------------------------------------|
| Core Frequency | 20 MHz                                 |
| SoC Frequency  | 10 MHz                                 |


## Peripherals
Please review constraint file for current peripheral mapping.

### Reset Button
The BTNC is connected as reset button.

### JTAG
Since there is no way of connecting to on-board FTDI USB JTAG programmer there is a configuration for
Digilent HS-2 programmer, which can be connected to PMOD A (JA1-JA4).

Notice that ZedBoard uses the same FTDI chip, so to make it work change the serial number in provided
`openocd-zedboard-hs2.cfg` if you want to have it connected simultaneously with ZedBoard. If you have
Vivado running remember to disconnect the target and close HW Manager before attmpting to use OpenOCD.
Otherwise there will be an error about target being busy.

```Shell
$OPENOCD/bin/openocd -f pulpissimo/fpga/pulpissimo-nexys_video/openocd-nexys_video.cfg
```
