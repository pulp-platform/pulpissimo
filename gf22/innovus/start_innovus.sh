
# Run innovus with version from .cockpitrc
eval `cat ../.cockpitrc | grep innovus | grep xterm | cut -d\" -f 2`
