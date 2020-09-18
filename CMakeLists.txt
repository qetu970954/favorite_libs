cmake_minimum_required(VERSION 3.15)
project(3rd_party)
set(CMAKE_CXX_STANDARD 14)

# Separating libraries and executables in different directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include 3rd hardware
add_subdirectory(third_party)

# Include src_cpp
add_subdirectory(src_cpp)
