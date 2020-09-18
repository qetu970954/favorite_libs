# Include the 3rd lib globally so source codes can utilize them
include_directories(${PROJECT_SOURCE_DIR}/third_party)

# Add tests
add_subdirectory(tests)

# Add executables
add_executable(main main.cpp)
target_link_libraries(main 3rd)
