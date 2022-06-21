#!/bin/bash

set -e

CUR_DIR=$(cd "$(dirname "$0")";pwd)
CUR_FILE=${CUR_DIR}/export1.cc

emcc ${CUR_FILE} -o export1.js
