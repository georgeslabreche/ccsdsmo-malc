#!/bin/sh

# check if the app is already running
result=`ps aux | grep -i "sepp_tm_app" | grep -v "grep" | wc -l`
if [ $result -ge 1 ]
    then
        # exit this script if the program is already running
        exit 0
    else
        # run th program if it's not already running

        # first remove the file that serves as a flag to exit the program loop
        # this file is created when invoking the stop script
        rm -f .stop

        # run the program
        ./sepp_tm_app "$@"

        # exit the script
        exit 0
fi