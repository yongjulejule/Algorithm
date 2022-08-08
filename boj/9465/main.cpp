#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <cstring>
#include <iostream>
#endif  // gcc or not

using namespace std;

int DP[2][100001];
int sticker[2][100001];

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int testCase;
  cin >> testCase;
  while (testCase--) {
    int stikerSZ;
    cin >> stikerSZ;
    memset(DP, 0, sizeof(DP));
    memset(sticker, 0, sizeof(stikerSZ));

    for (int i = 0; i < 2; ++i) {
      for (int j = 1; j <= stikerSZ; ++j) {
        cin >> sticker[i][j];
      }
    }
    DP[0][1] = sticker[0][1];
    DP[1][1] = sticker[1][1];
    for (int i = 2; i <= stikerSZ; ++i) {
      DP[0][i] = max(DP[1][i - 1], DP[1][i - 2]) + sticker[0][i];
      DP[1][i] = max(DP[0][i - 1], DP[0][i - 2]) + sticker[1][i];
    }
    cout << max(DP[0][stikerSZ], DP[1][stikerSZ]) << '\n';
  }
  return 0;
}
