#!/bin/bash

VNX_INTERFACE_DIR=${VNX_INTERFACE_DIR:-/usr/interface}

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ example interface/ modules/ ${VNX_INTERFACE_DIR}/vnx/ ${VNX_INTERFACE_DIR}/basic/ ${VNX_INTERFACE_DIR}/math/

