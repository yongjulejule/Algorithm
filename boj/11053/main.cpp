#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#endif  // gcc or not

using namespace std;
uint16_t seq[1001];
uint16_t DP[1001];

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  uint16_t N, ans = 0;
  cin >> N;
  for (uint16_t i = 1; i <= N; ++i) {
    cin >> seq[i];
  }
  for (int i = 1; i <= N; ++i) {
    DP[i] = 1;
    for (int j = i - 1; j > 0; --j) {
      if (seq[i] > seq[j]) {
        DP[i] = max(DP[i], uint16_t(DP[j] + 1));
      }
    }
    ans = max(DP[i], ans);
  }
  cout << ans;
}