add_executable(cpput test_sample.cc) # CPP unittest
target_include_directories(cpput PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
target_link_libraries(cpput 3rd)
