#!/usr/bin/env sh

gsl project.xml

chmod +x autogen.sh
if [ -e version.sh ];then
chmod +x version.sh
fi
