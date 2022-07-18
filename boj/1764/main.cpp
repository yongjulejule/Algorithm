#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int nl, ns;
  cin >> nl >> ns;
  unordered_set<string> nL;
  set<string> nS;
  string inStr;
  while (nl--) {
    cin >> inStr;
    nL.insert(inStr);
  }
  while (ns--) {
    cin >> inStr;
    if (nL.find(inStr) != nL.end()) nS.insert(inStr);
  }
  cout << nS.size() << '\n';
  for (auto &e : nS) cout << e << '\n';
}