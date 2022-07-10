// 1 2 3 4 5 ...    i
// 1 3 6 10 15 ...  i + 1
// 1 4 10 20 35 ...
// 1 5 15 35 70 ...
// 1 6 21 56 126 ...

#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int build[15][15];
  for (int i = 0; i < 15; ++i) {
    for (int j = 1; j < 15; ++j) {
      if (i == 0)
        build[i][j] = j;
      else if (j == 1)
        build[i][j] = 1;
      else
        build[i][j] = build[i - 1][j] + build[i][j - 1];
    }
  }
  while (N--) {
    int k, n;
    cin >> k >> n;
    cout << build[k][n] << "\n";
  }
}