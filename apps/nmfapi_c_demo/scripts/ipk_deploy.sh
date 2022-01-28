#!/usr/bin/env bash

# Set the bash script variables.
source env.sh

# Enter directory that contains the ipk file.
cd sepp_package

# Deploy the ipk file to the sepp them to SEPP.
scp -P2223 *.ipk  root@localhost:${SEPP_BIN_DIR}