#!/usr/bin/env bash
set -euo pipefail
mkdir -p build && clang++ example.cc -std=c++17 -g -o build/example