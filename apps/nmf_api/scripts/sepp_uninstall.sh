# Set the bash script variables.
source env.sh

# Delete malc shared libs.
rm -f ${SEPP_LIB_DIR}/libmal.so*
rm -f ${SEPP_LIB_DIR}/libmalactor.so*
rm -f ${SEPP_LIB_DIR}/libmalattributes.so*
rm -f ${SEPP_LIB_DIR}/libmalbinary.so*
rm -f ${SEPP_LIB_DIR}/libmalsplitbinary.so*
rm -f ${SEPP_LIB_DIR}/libmaltcp.so*
rm -f ${SEPP_LIB_DIR}/libmalzmq.so*
rm -f ${SEPP_LIB_DIR}/libutil.so*

# Delete generated areas lib.
rm -f ${SEPP_LIB_DIR}/libgenerated_areas.so*

# Delete czmq lib.
rm -f ${SEPP_LIB_DIR}/libczmq.so*

# Delete zmq lib.
rm -f ${SEPP_LIB_DIR}/libzmq.so*

# Delete app lib.
rm -f ${SEPP_LIB_DIR}/lib${PROJECT_NAME}.so*

# Delete app bin.
rm -f ${SEPP_BIN_DIR}/${BIN_FILENAME}