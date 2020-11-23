# Add abseil support
option(ABSL_RUN_TESTS OFF)
add_subdirectory(abseil-cpp)

# Add json support
set(SIMDJSON_JUST_LIBRARY ON CACHE INTERNAL "")
set(SIMDJSON_BUILD_STATIC ON CACHE INTERNAL "")
add_subdirectory(simdjson)

# Add google test support
add_subdirectory(googletest)

# Add spdlog
add_subdirectory(spdlog)

# Build all libraries into a single header
add_library(3rd 3rd_party.hpp)
target_include_directories(3rd PUBLIC abseil-cpp indicators/include)
target_link_libraries(3rd absl::strings simdjson gtest_main gtest spdlog::spdlog_header_only)
