#!/bin/bash

set -e

CUR_DIR=$(cd "$(dirname "$0")";pwd)
CUR_FILE=${CUR_DIR}/export1.cc

emcc -m64 -g -O0 ${CUR_FILE} -s WASM=1 --js-library pkg.js -o export1.js -v
