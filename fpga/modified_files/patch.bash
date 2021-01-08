pushd ../../ips
git clone https://github.com/openhwgroup/cv32e40p
cd cv32e40p
git checkout tags/cv32e40p_v1.0.0
popd
cp -r ips ../../.
cp *.tcl ../pulpissimo/tcl
