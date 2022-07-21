#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCase;
  cin >> testCase;
  int ops;
  char op;
  int num;
  multiset<int> ms;
  while (testCase--) {
    cin >> ops;
    while (ops--) {
      cin >> op >> num;
      if (op == 'D') {
        if (!ms.empty()) num == 1 ? ms.erase(--ms.end()) : ms.erase(ms.begin());
      } else {
        ms.insert(num);
      }
    }
    ms.empty() ? (cout << "EMPTY\n")
               : cout << *--ms.end() << ' ' << *(ms.begin()) << '\n';
    ms.clear();
  }
}