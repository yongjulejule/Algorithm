#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  getline(cin, s);
  auto pos = s.begin();
  find_if(pos, s.end(), [](char &c) { return c == '+' || c == '-'; });
}