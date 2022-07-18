#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  int values[10];
  memset(values, 0, sizeof(values));
  for (int i = 0; i < N; ++i) {
    cin >> values[i];
  }
  int cnt = 0;
  for (int i = N - 1; i >= 0; --i) {
    while (values[i] <= K) {
      K -= values[i];
      ++cnt;
    }
  }
  cout << cnt;
}