#!/bin/bash

#import common variables
source common_variables.sh

#check if build directory doesnot exist
if [ ! -d "$BUILD_DIR" ]
then
    echo "Build Directory doesnt exist in current working directory, create one.."
    mkdir -p "$BUILD_DIR"
else
    echo "Build Directory exists, clear contents of the build directory : "$BUILD_DIR"/* "
    rm -rf "$BUILD_DIR"/*
    echo "Contents of the build directory : "
    ls -la "$BUILD_DIR"
fi

#Change to build directory
cd "$BUILD_DIR"

#run cmake command to build using cmake in 
cmake ..
