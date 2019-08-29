
# Run synopsys with version from .cockpitrc
eval `cat ../.cockpitrc | grep synopsys | grep DC | cut -d\" -f 2 | cut -d\' -f 2`
