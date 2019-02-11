PROJECT:=pulpissimo

all:
	vivado -mode batch -source tcl/run.tcl

gui:
	vivado -mode gui -source tcl/run.tcl &

clean:
	rm -rf ${PROJECT}.*[^'bit']
	rm -rf *.log
	rm -rf vivado*


