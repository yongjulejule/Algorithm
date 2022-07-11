#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (true) {
    string s;
    getline(cin, s);
    if (s[0] == '.' && s.size() == 1) break;
    stack<char> stk;
    for (auto &c : s) {
      if (c == '(' || c == '[') {
        stk.push(c);
      } else if (c == ')') {
        if (stk.empty()) {
          stk.push('.');
          break;
        }
        if (stk.top() == '(')
          stk.pop();
        else {
          stk.push('.');
          break;
        }
      } else if (c == ']') {
        if (stk.empty()) {
          stk.push('.');
          break;
        }
        if (stk.top() == '[')
          stk.pop();
        else {
          stk.push('.');
          break;
        }
      }
    }
    if (stk.empty())
      cout << "yes\n";
    else
      cout << "no\n";
  }
}