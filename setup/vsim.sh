if [ -n "$ZSH_VERSION" ]; then
    ROOT=$(cd "$(dirname "${(%):-%N}")/.." && pwd)
else
    ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
fi
export VSIM_PATH="$ROOT"/sim
