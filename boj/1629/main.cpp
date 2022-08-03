#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <cstdint>
#include <iostream>
#endif  // gcc or not

using namespace std;

uint64_t DP[33];

inline uint32_t getMSB(uint32_t val) {
  uint32_t msb = 0;
  while (val) {
    val >>= 1;
    ++msb;
  }
  return msb;
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  uint32_t A, B, C;
  cin >> A >> B >> C;
  bitset<32> bBit(B);
  const uint32_t bSize = getMSB(B);
  DP[0] = 0;
  DP[1] = A % C;
  for (uint32_t i = 2; i <= bSize; ++i) {
    DP[i] = (DP[i - 1] * DP[i - 1]) % C;
  }

  uint64_t ans = 1;
  for (uint32_t i = 0; i < bSize; ++i) {
    if (bBit[i]) {
      ans *= DP[i + 1];
      ans %= C;
    }
  }
  cout << ans % C << '\n';
}