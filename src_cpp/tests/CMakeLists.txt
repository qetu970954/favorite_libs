add_executable(test test_sample.cc)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
target_link_libraries(test 3rd)
