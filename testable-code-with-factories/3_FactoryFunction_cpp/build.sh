#!/usr/bin/env bash
set -euo pipefail
mkdir -p build && clang++ main.cc -std=c++17 -g -o build/main

cmake -S . -B build
cmake --build build