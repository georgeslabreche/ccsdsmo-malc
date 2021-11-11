#!/usr/bin/env bash

# Creates the ipk file to install this project into the sepp.
# Pre-requisite: run the build4targets.sh bash script (this will take some time to complete).

# Include some verbosity along the way.
echo "Create IPK"

# Set the bash script variables.
source env.sh

# Extract the package name, version, and architecture from the control file.
PKG_NAME=$(sed -n -e '/^Package/p' sepp_package/CONTROL/control | cut -d ' ' -f2)
PKG_VER=$(sed -n -e '/^Version/p' sepp_package/CONTROL/control | cut -d ' ' -f2)
PKG_ARCH=$(sed -n -e '/^Architecture/p' sepp_package/CONTROL/control | cut -d ' ' -f2)

# Clean and initialize the ipk repo.
if [ -d sepp_package${SEPP_LIB_DIR} ] ; then rm -r sepp_package${SEPP_LIB_DIR}; fi
mkdir -p sepp_package${SEPP_LIB_DIR}
mkdir -p sepp_package${SEPP_BIN_DIR}
cd sepp_package
rm -f data.tar.gz
rm -f control.tar.gz

echo "Fetch binary and library dependency"

# Fetch this project's library files.
cp ../${LOCAL_APP_LIB_DIR}/*${PKG_NAME}*.so* ../sepp_package${SEPP_LIB_DIR}

# Fetch this project's executable binary file
cp ../../src/${BIN_FILENAME} ../sepp_package${SEPP_BIN_DIR}

echo "Package"

# Create the control tar file.
cd CONTROL && 
tar -czvf control.tar.gz control postinst postrm preinst prerm
mv control.tar.gz ../
cd ..

# Create the data tar file.
tar -czvf data.tar.gz usr home

# Build the ipk filename.
IPK_FILENAME=${PKG_NAME}_${PKG_VER}_${PKG_ARCH}.ipk

# Delete ipk file if it already exists for the target version.
rm -f ${IPK_FILENAME}

# Create the ipk file.
ar rv ${IPK_FILENAME} control.tar.gz data.tar.gz debian-binary
echo "Created ${IPK_FILENAME}"

# Cleanup.
echo "Cleanup"

rm -f data.tar.gz
rm -f control.tar.gz
rm -r ../sepp_package${SEPP_LIB_DIR}

# Done
echo "Done"