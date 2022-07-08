#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int b, e;
  cin >> b >> e;
  int *in = new int[e - b + 1];
  for (int i = b; i <= e; ++i) {
    in[i - b] = i;
  }
  vector<bool> v(e + 1, true);
  v[0] = false;
  v[1] = false;
  for (int i = 2; i < e; ++i) {
    if (v[i]) {
      for (int j = 2; i * j <= e; ++j) {
        v[i * j] = false;
      }
    }
  }
  for_each(in, in + e - b + 1, [&](int i) {
    if (v[i]) {
      cout << i << "\n";
    }
  });
  delete[] in;
  return 0;
}