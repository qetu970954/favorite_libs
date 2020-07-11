#pragma once

// Include absl libs
#include "absl/strings/str_replace.h"
#include "absl/strings/str_join.h"

// Include indicator libs (only available on unix)
#ifdef unix
#include "indicators/progress_bar.hpp"
#endif

// Include gtest libs
#include "gtest/gtest.h"

// Include json libs
#include "nlohmann/json.hpp"
using json = nlohmann::json;

// Include std libs
#include <vector>
#include <array>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

