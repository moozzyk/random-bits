#!/usr/bin/env bash
set -euo pipefail
mkdir -p build && clang++ initial.cc -std=c++17 -g -o build/initial