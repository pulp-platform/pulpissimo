ifndef help_mk
help_mk = 1

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# Makefile Autodocumentation:
#
# This utility makefile in combination with the generate-makefile-help.sh shell
# script (also in this folder) allows for self-documenting makefiles by means of
# special comments. To enable support for this, just include this utils.mk AT
# THE VERY END of your Makefile to be documented
#
# This will provide a new phony target called 'help' that will print all
# documented targets in very nice colored format.
# 
# Here is the example on how to write documentation from the original author of
#the script (hilnius)



# # Line to add to any Supermood Makefile - generates the 'help' target from the Makefile comments
# include ${SUPERMOOD_ROOT}/tools/Makefile-help.mk
# 
# ## @section Installation
# 
# ## Install the Supermood environment (adds $SUPERMOOD_ROOT to your shell)
# install:
#   @echo Setting SUPERMOOD_ROOT environment
#   @./tools/bashrc-setup
# 
# ## @section Supermood Release log generation
# 
# ## Generates the production release log from git history.
# ## Post the output to the #releases slack channel
# ## @param FROM=1.234.0 Git reference from which we show the log
# ## @param TO=1.235.0 Git reference to which we show the log
# releaselog:
#   @./internal/releaselog/display-release-log $$FROM $$TO
# 
# ## Generates the full release log (including [no-releaselog] commits) from git history.
# ## Post the output to your squad's channel or #tech-team
# ## @param FROM=1.234.0 Git reference from which we show the log
# ## @param TO=1.235.0 Git reference to which we show the log
# full-releaselog:
#   @./internal/releaselog/display-full-release-log $$FROM $$TO
# 
# # This is just hidden, probably a target we don't want people to call
# sometarget: any other file
#   echo "hello"
# 
# .PHONY: install releaselog full-releaselog
# include utils/utils.mk


# ANSI Text Effects

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White
 

.PHONY: help
help:
ifdef HELP_TITLE
	@echo -e $(BPurple)$(HELP_TITLE)$(Color_Off)
endif
ifdef HELP_DESCRIPTION
	@echo $(HELP_DESCRIPTION)
endif
	@echo ""
	@MAKEFILES="$(MAKEFILE_LIST)" $(mkfile_dir)generate-makefile-help.sh

.PHONY: list-all-targets
list-all-targets:
	@LC_ALL=C $(MAKE) -pRrq -f $(THIS_FILE) : 2>/dev/null | awk -v RS= -F: '/(^|\n)# Files(\n|$$)/,/(^|\n)# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'
endif
