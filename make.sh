#!/bin/bash

mkdir -p build/devel

cd build/devel

cmake -D CMAKE_CXX_FLAGS="-g -O3 -fmax-errors=1" ../../

make -j8 $@

