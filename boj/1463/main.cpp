#include <cstring>
#include <iostream>

using namespace std;

int DP[1000001];

int main() {
  cin.ios::sync_with_stdio(0);
  cin.tie(nullptr);
  memset(DP, 0, sizeof(DP));
  int N;
  cin >> N;
  DP[1] = 0;
  DP[2] = 1;
  DP[3] = 1;
  for (int i = 4; i <= N; ++i) {
    DP[i] = DP[i - 1] + 1;
    if (i % 3 == 0) DP[i] = min(DP[i / 3] + 1, DP[i]);
    if (i % 2 == 0) DP[i] = min(DP[i / 2] + 1, DP[i]);
  }
  cout << DP[N];
}