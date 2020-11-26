#! /usr/bin/bash

set -euo pipefail

PROJECT_ROOT=$(pwd)
BUILD_TYPE=Debug # Debug / Release / RelWithDebInfo / MinSizeRel

# -------------------- Create out-of-source build
build_dir="$PROJECT_ROOT/build/$BUILD_TYPE"
printf "Build start at %s\n" "$PROJECT_ROOT"
mkdir -p "$build_dir"
cd "$build_dir"

# ------------------- Start build
build_cmake=true
if [ -f Makefile ]; then
  printf "Rebuild cmake (N for faster build)? (N/y) "
  read -r option
  if [[ $option == "N" || $option == "n" || $option == "" ]]; then
    build_cmake=false
  fi
fi

if [ $build_cmake = true ]; then
  cmake "$PROJECT_ROOT" -D CMAKE_BUILD_TYPE="$BUILD_TYPE"
fi

make -j $(($(nproc) * 3 / 4)) # parallel make using 3/4 of available processes
