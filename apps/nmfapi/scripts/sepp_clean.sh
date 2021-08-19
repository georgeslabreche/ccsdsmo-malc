# Set the bash script variables.
source env.sh

# Delete files and folders
./sepp_uninstall.sh
rm -rf builds
rm -f ${TAR_FILENAME}
rm -f sepp_install.sh 
rm -f sepp_uninstall.sh
rm -f env.sh