#include <iostream>
#include <string>
#include <vector>
#include "absl/strings/str_join.h"

int main() {
  using namespace std;

  {
    vector<string> v = {"foo", "bar", "baz"};
    string s = absl::StrJoin(v, "-");
    cout << __LINE__ << " " << s << "\n";                                             // foo-bar-baz
  }
  {
    cout << __LINE__ << " " << absl::StrCat(1, 3) << "\n";                            // 13
    cout << __LINE__ << " " << absl::StrCat(1.0f / 3) << "\n";                        // 0.333333
    cout << __LINE__ << " " << absl::StrCat(1, "_and_", 2) << "\n";                   // 1_and_2
    cout << __LINE__ << " " << absl::StrCat(absl::Dec(12, absl::kZeroPad4)) << "\n";  // 0012
    cout << __LINE__ << " " << absl::StrCat(absl::Hex(12, absl::kZeroPad4)) << "\n";  // 000c
  }
}
