# The name of the project.
PROJECT_NAME="nmfapi"

# Build library path.
BUILD_LIB_PATH="builds/rpi/tmp/lib"

# Deploy directory name.
DEPLOY_DIR="deploy"

# Tar paths.
TAR_FILENAME="malc_nmfapi.tar.gz"
TAR_PATH="${DEPLOY_DIR}/${TAR_FILENAME}"
TAR_EXTRACT_LIB_PATH=${BUILD_LIB_PATH}

# Local build paths.
LOCAL_APP_LIB_DIR="../${BUILD_LIB_PATH}"

# SEPP deployment paths.
SEPP_LIB_DIR="/usr/lib"
SEPP_DEPLOY_DIR="/home/root/georges/apps/malc/nmfapi" # Change this if needed.