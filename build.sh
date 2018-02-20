#!/bin/bash

if test $# -ne 1
then
    echo "Wrong arg"
else
    if test $1 = "build"
    then
        echo "-build-"
        echo "----server"
        cd ./ser/
        make
        cd ..
        echo "client----"
        cd ./cli/
        make
        cd ..
    elif test $1 = "clean"
    then
        echo "-clean-"
        echo "----server"
        cd ./ser/
        make clean
        cd ..
        echo "client----"
        cd ./cli/
        make clean
        cd ..
    else
        echo "arg is wrong."
    fi
fi
