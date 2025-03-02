#!/bin/bash

set -e

if [ -z "$1" ]; then
    echo "Usage: $0 <build-type>"
    echo "Example: $0 release"
    exit 1
fi

BUILD_TYPE=$1
BUILD_TYPE="$(tr '[:lower:]' '[:upper:]' <<< ${BUILD_TYPE:0:1})${BUILD_TYPE:1}"

cmake --preset=flatland -S . -B out/build/flatland -DCMAKE_BUILD_TYPE=$BUILD_TYPE