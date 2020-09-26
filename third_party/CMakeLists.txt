# Add abseil support
option(ABSL_RUN_TESTS OFF)
add_subdirectory(abseil-cpp)

# Add json support
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(json)

# Add google test support
add_subdirectory(googletest)

# Add spdlog
add_subdirectory(spdlog)

# Build all libraries into a single header
add_library(3rd 3rd_party.hpp)
target_include_directories(3rd PUBLIC abseil-cpp indicators/include)
target_link_libraries(3rd absl::strings nlohmann_json::nlohmann_json gtest_main gtest spdlog::spdlog_header_only)

