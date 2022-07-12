#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
static const int M = 1234567891;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int L;
  string s;
  cin >> L >> s;
  const int len = s.length();
  uint64_t sum = s[0] - 96;
  uint64_t r = 31;
  for (int i = 1; i < len; ++i) {
    sum = ((sum % M) + (((s[i] - 96) * static_cast<int>(pow(r, i))) % M)) % M;
  }
  cout << sum << "\n";
}