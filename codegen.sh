#!/bin/bash

cd $(dirname "$0")

vnxcppcodegen --cleanup generated/ example interface/ modules/ /usr/interface/vnx/ /usr/interface/basic/ /usr/interface/math/

