#!/bin/bash

mkdir -p build/debug

cd build/debug

cmake -D CMAKE_CXX_FLAGS="-g -fmax-errors=1" -D CUDA_NVCC_FLAGS="-G" ../../

make -j8 $@

