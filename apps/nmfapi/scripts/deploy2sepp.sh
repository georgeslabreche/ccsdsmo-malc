#!/usr/bin/env bash

# Set the bash script variables.
source env.sh

# Delete and recreate deploy directory.
rm -rf ${DEPLOY_DIR}
mkdir ${DEPLOY_DIR}

# Tar the artifacts and deploy them to SEPP.
tar -czvf ${TAR_PATH} ${LOCAL_APP_LIB_DIR}/*.so* sepp_*.sh env.sh
scp -P2223 ${TAR_PATH} root@localhost:${SEPP_DEPLOY_DIR}