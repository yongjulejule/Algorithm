#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCase, nbr;
  cin >> testCase;

  string garment, kind;
  while (testCase--) {
    int sum = 0;
    cin >> nbr;
    map<string, int> fashion;
    while (nbr--) {
      cin >> garment >> kind;
      ++fashion[kind];
    }
    int ret = 1;
    for (auto v : fashion) {
      ret *= (v.second + 1);
    }
    cout << ret - 1 << '\n';
  }
}