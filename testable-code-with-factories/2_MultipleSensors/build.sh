#!/usr/bin/env bash
set -euo pipefail
mkdir -p build && clang++ multiple_sensors.cc -std=c++17 -g -o build/multiple_sensors
