# The name of the project.
# Extract the project name from the control file (set as the package name).
PROJECT_NAME=$(sed -n -e '/^Package/p' sepp_package/CONTROL/control | cut -d ' ' -f2)

# lib and bin directories.
BUILD_LIB_PATH="builds/rpi/tmp/lib"
BUILD_BIN_PATH="builds/rpi/tmp/bin"

# Local build paths.
LOCAL_APP_LIB_DIR="../${BUILD_LIB_PATH}"
LOCAL_APP_BIN_DIR="../${BUILD_BIN_PATH}"

# Deployment paths on the SEPP.
SEPP_LIB_DIR="/usr/lib"
SEPP_BIN_DIR="/home/root/georges/apps/malc/${PROJECT_NAME}" # Change this if needed.