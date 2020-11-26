#! /usr/bin/bash

set -euo pipefail

PROJECT_ROOT=$(pwd)
BUILD_TYPE=Debug # Debug / Release / RelWithDebInfo / MinSizeRel
BUILD_DIR="$PROJECT_ROOT/build/$BUILD_TYPE"

# -------------------- Create out-of-source build
printf "Build start at %s\n" "$PROJECT_ROOT"
mkdir -p "$BUILD_DIR"

# ------------------- Start building C++ program
cd "$BUILD_DIR"
build_cmake=true
if [ -f Makefile ]; then
  printf "Rebuild cmake (N for faster build)? (N/y) "
  read -r option
  if [[ $option == "N" || $option == "n" || $option == "" ]]; then
    build_cmake=false
  fi
fi

if [ $build_cmake = true ]; then
  find . -delete && cmake "$PROJECT_ROOT" -D CMAKE_BUILD_TYPE="$BUILD_TYPE"
fi

make -j $(($(nproc) * 3 / 4)) # parallel make using 3/4 of available processors

# ------------------- Unittest C++
./bin/cpput

# ------------------- Build python3 environment
cd "$PROJECT_ROOT"/src_py

# Check if python virtual environment has been built before.
if [ ! -d .venv ]; then
  # Virtual environment does NOT exist, create it locally
  export PIPENV_VENV_IN_PROJECT=1
  pipenv update
fi

pipenv run pytest --rootdir="$BUILD_DIR"
