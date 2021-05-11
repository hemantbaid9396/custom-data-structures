#!/bin/bash

#import common variables
source common_variables.sh

if [ ! -d "$BUILD_DIR" ]
then
    echo "Project not built, building the project"
    ./generate_build_files.sh
else
    echo "Project build directory exists, continue to build application"
fi

#move to build directory
cd "$BUILD_DIR"

#run make command to make the application executable
make all

