#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
static const int M = 1234567891;
static const int r = 31;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int L;
  string s;
  cin >> L >> s;
  const int len = s.length();
  uint64_t sum = s[0] - 96;
  uint64_t rMod = r;
  for (int i = 1; i < len; ++i) {
    sum = ((sum % M) + (((s[i] - 96) * rMod) % M)) % M;
    rMod = ((rMod % M) * r) % M;
  }
  cout << sum << "\n";
}

// (a + b*r + c*r*r + d*r*r*r ...) MOD M
// (a % M + (b * r + c * r * r + d * r *r *r) % M)%M
// ((a % M) + ((b * r) % M + (c * r * r + d * r * r * r) % M) % M) % M
// ((a % M) + ((b * r) % M + (c * r * r % M + d * r * r * r % M) % M) % M) % M
// ((a % M) + ((b * r % M) % M)
// r^2 % M == (r % M * r % M) % M == (r % M)^2 % M
// r^3 % M == (((r % M * r % M) % M) * r % M) % M