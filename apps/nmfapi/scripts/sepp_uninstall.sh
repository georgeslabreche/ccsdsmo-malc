# Set the bash script variables.
source env.sh

# Delete project lib.
rm -f ${SEPP_LIB_DIR}/lib${PROJECT_NAME}.so*

# Delete generated areas lib.
rm -f ${SEPP_LIB_DIR}/libgenerated_areas.so*

# Delete malc shared libs.
rm -f ${SEPP_LIB_DIR}/libmalutil.so*
rm -f ${SEPP_LIB_DIR}/libmal.so*
rm -f ${SEPP_LIB_DIR}/libmalactor.so*
rm -f ${SEPP_LIB_DIR}/libmalattributes.so*
rm -f ${SEPP_LIB_DIR}/libmalbinary.so*
rm -f ${SEPP_LIB_DIR}/libmalsplitbinary.so*
rm -f ${SEPP_LIB_DIR}/libmaltcp.so*
rm -f ${SEPP_LIB_DIR}/libmalzmq.so*

# Delete czmq lib.
rm -f ${SEPP_LIB_DIR}/libczmq.so*

# Delete zmq lib.
rm -f ${SEPP_LIB_DIR}/libzmq.so*