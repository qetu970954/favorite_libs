#pragma once

// absl libs
#include "absl/strings/str_replace.h"
#include "absl/strings/str_join.h"

// indicator libs (only available in unix)
#ifdef unix
#include "indicators/progress_bar.hpp"
#endif

// json libs
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// std libs
#include <vector>
#include <array>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

