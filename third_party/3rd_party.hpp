#pragma once

// Include absl libs
#include "absl/strings/str_join.h"
#include "absl/strings/str_replace.h"

// Include indicator libs (only available on unix)
#ifdef unix
#include "indicators/progress_bar.hpp"
#include <indicators/cursor_control.hpp>
#endif

// Include spdlog
#include "spdlog/spdlog.h"

// Include gtest libs
#include "gtest/gtest.h"

// Include json libs
#include "simdjson.h"

// Include std libs
#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using std::cerr;
using std::cout;
using std::list;
using std::string;
using std::vector;
using namespace std::string_literals;
