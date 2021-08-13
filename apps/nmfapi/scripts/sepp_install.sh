# Set the bash script variables.
source env.sh

# Move untarred files.
mv ${TAR_EXTRACT_LIB_PATH}/*.so* ${SEPP_LIB_DIR}
mv ${TAR_EXTRACT_BIN_PATH}/${BIN_FILENAME} ${SEPP_BIN_DIR}