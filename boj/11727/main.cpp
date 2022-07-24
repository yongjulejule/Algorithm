#include <algorithm>
#include <iostream>

using namespace std;
int DP[1001];
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  DP[0] = 0;
  DP[1] = 1;
  DP[2] = 3;
  DP[3] = 5;
  DP[4] = 11;
  DP[5] = 21;

  int N;
  cin >> N;
  for (int i = 5; i <= N; ++i)
    DP[i] = (DP[i - 1] % 10007) + ((DP[i - 2] * 2) % 10007);
  cout << (DP[N] % 10007);
}