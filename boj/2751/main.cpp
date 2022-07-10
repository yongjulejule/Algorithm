#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  set<int> s;
  while (N--) {
    int nbr;
    cin >> nbr;
    s.insert(nbr);
  }
  // for_each(s.begin(), s.end(), [](int nbr) { cout << nbr << "\n"; });
  for (const int &n : s) cout << n << "\n";
  return 0;
}