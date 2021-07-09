# Set the bash script variables.
source env.sh

# Delete malc shared libs.
rm -f ${SEPP_LIB_DIR}/libmal.so
rm -f ${SEPP_LIB_DIR}/libmal.so.0
rm -f ${SEPP_LIB_DIR}/libmal.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmalactor.so
rm -f ${SEPP_LIB_DIR}/libmalactor.so.0
rm -f ${SEPP_LIB_DIR}/libmalactor.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmalattributes.so
rm -f ${SEPP_LIB_DIR}/libmalattributes.so.0
rm -f ${SEPP_LIB_DIR}/libmalattributes.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmalbinary.so
rm -f ${SEPP_LIB_DIR}/libmalbinary.so.0
rm -f ${SEPP_LIB_DIR}/libmalbinary.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmalsplitbinary.so
rm -f ${SEPP_LIB_DIR}/libmalsplitbinary.so.0
rm -f ${SEPP_LIB_DIR}/libmalsplitbinary.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmaltcp.so
rm -f ${SEPP_LIB_DIR}/libmaltcp.so.0
rm -f ${SEPP_LIB_DIR}/libmaltcp.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libmalzmq.so
rm -f ${SEPP_LIB_DIR}/libmalzmq.so.0
rm -f ${SEPP_LIB_DIR}/libmalzmq.so.0.0.0
rm -f ${SEPP_LIB_DIR}/libutil.so
rm -f ${SEPP_LIB_DIR}/libutil.so.0
rm -f ${SEPP_LIB_DIR}/libutil.so.0.0.0

# Delete generated areas lib.
rm -f ${SEPP_LIB_DIR}/libgenerated_areas.so
rm -f ${SEPP_LIB_DIR}/libgenerated_areas.so.0
rm -f ${SEPP_LIB_DIR}/libgenerated_areas.so.0.0.0

# Delete czmq lib.
rm -f ${SEPP_LIB_DIR}/libczmq.so
rm -f ${SEPP_LIB_DIR}/libczmq.so.3
rm -f ${SEPP_LIB_DIR}/libczmq.so.3.0.0

# Delete zmq lib.
rm -f ${SEPP_LIB_DIR}/libzmq.so
rm -f ${SEPP_LIB_DIR}/libzmq.so.4
rm -f ${SEPP_LIB_DIR}/libzmq.so.4.0.3

# Delete app lib.
rm -f ${SEPP_LIB_DIR}/lib${PROJECT_NAME}.so
rm -f ${SEPP_LIB_DIR}/lib${PROJECT_NAME}.so.0
rm -f ${SEPP_LIB_DIR}/lib${PROJECT_NAME}.so.0.0.0

# Delete app bin.
rm -f ${SEPP_BIN_DIR}/${BIN_FILENAME}