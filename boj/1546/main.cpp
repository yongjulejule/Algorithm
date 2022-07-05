#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n = 0;
  cin >> n;
  vector<float> v;
  for (int i = 0; i < n; ++i) {
    int j;
    cin >> j;
    v.push_back(j);
  }
  auto m = *max_element(v.begin(), v.end());
  transform(v.begin(), v.end(), v.begin(),
            [m](float x) { return (x / m) * 100; });
  float ret = 0;
  for (auto x : v) {
    ret += x;
  }
  cout << ret / n << "\n";
  return 0;
}