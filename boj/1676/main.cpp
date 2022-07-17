#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 0; i <= N; ++i) {
    int j = i;
    while (j && j % 5 == 0) {
      ++cnt;
      j /= 5;
    }
  }
  cout << cnt;
}