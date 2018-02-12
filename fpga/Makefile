PROJECT:=pulpissimo

all:
	vivado -mode batch -source tcl/run.tcl

gui:
	vivado -mode gui -source tcl/run.tcl &

clean:
	rm -rf ${PROJECT}.xpr
	rm -rf ${PROJECT}.data
	rm -rf ${PROJECT}.runs
	rm -rf ${PROJECT}.srcs
	rm -rf ${PROJECT}.cache
	rm -rf ${PROJECT}.hw

