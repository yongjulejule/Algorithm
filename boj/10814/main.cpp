#include <iostream>
#include <map>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  multimap<int, string> m;
  while (N--) {
    int nai;
    string name;
    cin >> nai >> name;
    m.insert({nai, name});
  }
  for (auto &i : m) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}