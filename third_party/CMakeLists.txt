option(ABSL_RUN_TESTS OFF)
add_subdirectory(abseil-cpp)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(json)

add_library(3rd 3rd.hpp)
target_include_directories(3rd PUBLIC abseil-cpp indicators/include)
target_link_libraries(3rd absl::strings nlohmann_json::nlohmann_json)
