#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n[3];
  cin >> n[0] >> n[1] >> n[2];
  string s = to_string(n[0] * n[1] * n[2]);
  vector<int> v(10);
  for (auto &c : s) {
    v[c - '0']++;
  }
  for (auto &e : v) {
    cout << e << "\n";
  }
}