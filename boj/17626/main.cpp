#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int DP[50000];
int p[225];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  DP[0] = 0;
  DP[1] = 1;
  DP[2] = 2;
  DP[3] = 3;
  DP[4] = 1;
  int N;
  cin >> N;
  const int sqrtN = sqrtf(N);
  const int nearN = powf(sqrtN, 2);

  for (int i = 1, pw; i <= sqrtN; ++i) {
    pw = i * i;
    DP[pw] = 1;
    p[i] = pw;
  }
  for (int i = 5; i <= N; ++i) {
    int sq = static_cast<int>(sqrt(i));
    DP[i] = DP[p[sq]] + DP[i - p[sq]];
    for (; sq >= 0; --sq) {
      DP[i] = min(DP[i], DP[p[sq]] + DP[i - p[sq]]);
    }
  }
  cout << DP[N];
}
