#include <iostream>
#include <map>

using namespace std;

int main() {
  map<int, int> m;
  for (int i = 0; i < 9; ++i) {
    int a;
    cin >> a;
    m.insert(make_pair(a, i));
  }
  auto ret = --m.end();
  cout << ret->first << "\n" << ret->second + 1 << "\n";
  return 0;
}