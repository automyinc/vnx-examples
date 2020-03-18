#!/bin/bash

mkdir -p data
cd data

for i in {0..9999}; do dd if=/dev/urandom bs=1K count=1 of=file$i; done

