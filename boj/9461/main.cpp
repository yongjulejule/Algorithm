#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  uint64_t DP[101];
  memset(DP, 0, sizeof(DP));
  DP[1] = 1, DP[2] = 1, DP[3] = 1, DP[4] = 2, DP[5] = 2, DP[6] = 3, DP[7] = 4,
  DP[8] = 5, DP[9] = 7, DP[10] = 9;
  for (uint64_t i = 11; i < 101; ++i) DP[i] = DP[i - 1] + DP[i - 5];
  int testCases;
  cin >> testCases;
  int idx;
  while (testCases--) {
    cin >> idx;
    cout << DP[idx] << '\n';
  }
}