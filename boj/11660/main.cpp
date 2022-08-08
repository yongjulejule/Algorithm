#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <iostream>
#endif  // gcc or not

using namespace std;

int Board[1025][1025];

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->sync_with_stdio(false);
  int SZ, cnt;
  cin >> SZ >> cnt;
  for (int i = 1; i <= SZ; ++i) {
    for (int j = 1; j <= SZ; ++j) {
      cin >> Board[i][j];
      Board[i][j] += Board[i - 1][j] + Board[i][j - 1] - Board[i - 1][j - 1];
    }
  }
  for (int i = 0; i < cnt; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << Board[x2][y2] - Board[x1 - 1][y2] - Board[x2][y1 - 1] +
                Board[x1 - 1][y1 - 1]
         << '\n';
  }
}
