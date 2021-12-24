# The name of the project.
PROJECT_NAME="sepp_tm"

# The name of the executable binary.
BIN_FILENAME="sepp_tm_app"

# lib and bin directories.
BUILD_LIB_PATH="builds/rpi/tmp/lib"
BUILD_BIN_PATH="builds/rpi/tmp/bin"

# Local build paths.
LOCAL_APP_LIB_DIR="../${BUILD_LIB_PATH}"
LOCAL_APP_BIN_DIR="../${BUILD_BIN_PATH}"

# Deployment paths on the SEPP.
SEPP_LIB_DIR="/usr/lib"
SEPP_BIN_DIR="/home/root/georges/apps/malc/${PROJECT_NAME}" # Change this if needed.