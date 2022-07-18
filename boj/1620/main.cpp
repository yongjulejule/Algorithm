#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  string s;
  map<string, int> strDoGam;
  map<int, string> numDoGam;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    strDoGam.insert({s, i + 1});
    numDoGam.insert({i + 1, s});
  }
  while (M--) {
    string s;
    cin >> s;
    if (isdigit(s[0])) {
      int num = stoi(s);
      cout << numDoGam[num] << '\n';
    } else
      cout << strDoGam[s] << "\n";
  }
}