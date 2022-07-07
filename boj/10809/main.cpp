#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int ch[26];
  memset(ch, -1, sizeof(ch));
  string s;
  cin >> s;
  int cnt = 0;
  for (char &c : s) {
    if (ch[c - 'a'] == -1) ch[c - 'a'] = cnt;
    ++cnt;
  };
  for_each(ch, ch + 26, [](int &x) { cout << x << ' '; });
  cout << "\n";
  return 0;
}