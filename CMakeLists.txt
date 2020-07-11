cmake_minimum_required(VERSION 3.16)
project(abseil)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/third_party)
add_subdirectory(third_party)
add_subdirectory(example)
