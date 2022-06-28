#!/bin/bash

set -e

CUR_DIR=$(cd "$(dirname "$0")";pwd)
CUR_FILE=${CUR_DIR}/export1.cc

emcc -g -O3 -s EXPORTED_FUNCTIONS="['_malloc', '_free', 'setValue']" -s ALLOW_MEMORY_GROWTH=1 ${CUR_FILE} -s WASM=1 --js-library pkg.js -o export1.js
