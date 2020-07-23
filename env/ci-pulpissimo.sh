# This script is mean to be used in a gitlabci setup
# var that points to this project's root
ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

echo "Setting up SDK"
source "$ROOT/env/env-sdk-2019.11.03.sh"
source "$ROOT/pkg/sdk/2019.11.03/configs/pulpissimo.sh"
source "$ROOT/pkg/sdk/2019.11.03/configs/platform-rtl.sh"
echo "Setting up VSIM"
source "$ROOT/setup/vsim.sh"
