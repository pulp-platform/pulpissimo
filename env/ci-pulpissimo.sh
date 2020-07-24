# This script is mean to be used in a gitlabci setup
# var that points to this project's root
ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

echo "Setting up SDK"
source "$ROOT/env/env-sdk-2020.01.01.sh"
source "$ROOT/pkg/sdk/2020.01.01/configs/pulpissimo.sh"
source "$ROOT/pkg/sdk/2020.01.01/configs/platform-rtl.sh"
echo "Setting up VSIM"
source "$ROOT/setup/vsim.sh"
