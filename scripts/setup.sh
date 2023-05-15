#!/bin/bash

# BE ADVISED, LIIBRARIES USED IN THIS PROJECT CAN HAVE DEPENDENCIES
# WHICH MUST BE INSTALLED ON YOUR SYSTEM BEFORE BUILDING
# IF YOU ARE A LINUX USER, YOU WILL BE ABLE TO INSTALL THEM VIA YOUR PACKAGE MANAGER (FOR MOST DISTRIBUTIONS)
# IF YOU ARE A MAC USER, YOU WILL HAVE TO INSTALL THEM MANUALLY OR BY USING HOMEBREW
# IF YOU ARE A WINDOWS USER, YOU WILL HAVE TO INSTALL THEM MANUALLY (god help you o-o)

# Release Build — Generate build files and set the build type
# cmake . -B src/api_server_cpp/build -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release

# Debug Build — Generate build files and set the build type
cmake . -B build -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_BUILD_TYPE=Debug

# Build using make
make -C build

# Run the server (disable this line if you do not want to run the server each time you build)
./build/APIServer
