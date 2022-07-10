#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int getDecomposeNum(int N, int div) {
  string s = to_string(div);
  for_each(s.begin(), s.end(), [&](char &c) { div += c - '0'; });
  return div;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  string s = to_string(N);
  int div = N - (s.size() * 9);
  int ret;
  for (; div < N; ++div) {
    ret = getDecomposeNum(N, div);
    if (ret == N) {
      cout << div << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
  return 0;
}