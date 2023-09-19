#!/usr/bin/env bash
set -euo pipefail
mkdir -p build && clang++ factory_function.cc -std=c++17 -g -o build/factory_funcion
