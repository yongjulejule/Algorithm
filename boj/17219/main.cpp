#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<string, string> ghanPW;
  int N, M;
  cin >> N >> M;
  string domain, pw;
  while (--N) {
    cout << N << "\n";
    cin >> domain >> pw;
    ghanPW.insert({domain, pw});
  }
  while (M--) {
    cin >> domain;
    cout << ghanPW[domain] << '\n';
  }
  return 0;
}