#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  auto it = s.begin();
  auto ite = s.end();
  transform(it, ite, s.begin(),
            [](unsigned char c) -> unsigned char { return toupper(c); });
  vector<int> v(26);
  for (auto& c : s) {
    ++v[c - 'A'];
  }
  auto test = max_element(v.begin(), v.end());
  (count(v.begin(), v.end(), *test) == 1)
      ? cout << static_cast<unsigned char>('A' + (test - v.begin())) << "\n"
      : cout << "?\n";
}