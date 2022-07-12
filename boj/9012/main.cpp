#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  while (N--) {
    string vps;
    stack<char> stk;
    cin >> vps;
    for (auto &c : vps) {
      if (c == '(')
        stk.push('(');
      else if (c == ')') {
        if (stk.empty()) {
          stk.push('h');
          break;
        } else
          stk.pop();
      }
    }
    if (stk.empty())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}