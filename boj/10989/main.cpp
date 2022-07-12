#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int data[10001];
  memset(data, 0, sizeof(data));
  int idx;
  for (int i = 0; i < N; ++i) {
    cin >> idx;
    ++data[idx];
  }
  for (int i = 0; i < 10001; ++i) {
    for (int j = 0; j < data[i]; ++j) cout << i << '\n';
  }
  return 0;
}