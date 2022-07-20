#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
void doDP(int *DP, int nbr, int cur) {
  if (DP[nbr]) {
    DP[cur] += DP[nbr];
  } else {
    for (int i = 1; i <= 3; ++i) {
      doDP(DP, cur - i, cur);
    }
  }
}
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int DP[12];
  memset(DP, 0, sizeof(DP));
  DP[1] = 1;
  DP[2] = 2;
  DP[3] = 4;
  DP[4] = 7;
  for (int i = 5; i < 12; ++i) doDP(DP, i, i);
  int testCases;
  cin >> testCases;
  int idx = 0;
  while (testCases--) {
    cin >> idx;
    cout << DP[idx] << '\n';
  }
}