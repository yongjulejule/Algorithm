#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#endif  // gcc or not

using namespace std;
int DP[501][501];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int N;
  cin >> N >> DP[0][0];
  int ret = 0;
  int last = N - 1;
  for (int i = 1; i < N - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      cin >> DP[i][j];
      if (j != 0 && i != j) {
        DP[i][j] += max(DP[i - 1][j - 1], DP[i - 1][j]);
        continue;
      }
      if (j == 0)
        DP[i][0] += DP[i - 1][0];
      else if (j == i)
        DP[i][j] += DP[i - 1][i - 1];
    }
  }
  for (int i = 0, tmp; i < N; ++i) {
    cin >> tmp;
    tmp += max(DP[last - 1][i - 1], DP[last - 1][i]);
    if (ret < tmp) ret = tmp;
  }
  cout << ret;
}