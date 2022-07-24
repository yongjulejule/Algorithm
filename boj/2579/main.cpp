#include <algorithm>
#include <iostream>

using namespace std;
int DP[301];
int stair[301];
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cnt;
  cin >> cnt;
  stair[0] = DP[0] = 0;
  for (int i = 1; i <= cnt; ++i) {
    int input;
    cin >> input;
    stair[i] = input;
  }
  DP[1] = stair[1];
  DP[2] = stair[1] + stair[2];
  for (int i = 3; i <= cnt; ++i) {
    DP[i] = max(DP[i - 3] + stair[i - 1], DP[i - 2]) + stair[i];
  }
  cout << DP[cnt];
}

// DP[0] = 0;        // stair[0];
// DP[1] = 10;       // stair[0] + stair[1];
// DP[2] = 30;       // stair[1] + stair[2];
// DP[3] = 25;       // DP[0] + stair[2] + stair[3] | DP[1] + stair[3]
// DP[4] = 55 | 50;  // DP[1] + stair[3] + stair[4] | DP[2] + stair[4]
// DP[5] = 35 | 65;  // DP[2] + stair[4] + stair[5] | DP[3] + stair[5]
// DP[6] = 75 | 55;  // DP[3] + stair[5] + stair[6] | DP[4] + stair[6]