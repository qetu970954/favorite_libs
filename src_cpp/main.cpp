#include "3rd_party.hpp"

void basic_progress_bar() {
  using namespace indicators;

  ProgressBar bar{option::BarWidth{50},
                  option::Start{"["},
                  option::Fill{"="},
                  option::Lead{">"},
                  option::Remainder{" "},
                  option::End{"]"},
                  option::PostfixText{"Extracting Archive"},
                  option::ForegroundColor{Color::green},
                  option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}};

  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed()) {
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
}

void spdlog_example() {
  // change log pattern
  // spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);
  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");
  spdlog::info("{:<30}", "left aligned");
  spdlog::set_level(spdlog::level::debug);  // Set global log level to debug
  spdlog::debug("This message should be displayed..");
}

int main() {
  cout << absl::StrCat("Hello ", 2020, " World\n");
  basic_progress_bar();
  spdlog_example();
  return 0;
}
