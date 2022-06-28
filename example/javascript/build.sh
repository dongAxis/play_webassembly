#!/bin/bash

set -e

CUR_DIR=$(cd "$(dirname "$0")";pwd)
CUR_FILE=${CUR_DIR}/simple.wat

wat2wasm ${CUR_FILE}
