#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#endif  // gcc or not

using namespace std;
int home[1001][3];
int DP[1001][3];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> home[i][0] >> home[i][1] >> home[i][2];
  }
  DP[0][0] = home[0][0], DP[0][1] = home[0][1], DP[0][2] = home[0][2];
  constexpr int idx[5] = {0, 1, 2, 0, 1};
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      DP[i][j] = min(DP[i - 1][idx[j + 1]], DP[i - 1][idx[j + 2]]) + home[i][j];
    }
  }
  cout << *min_element(DP[N - 1], DP[N - 1] + 3);
}
