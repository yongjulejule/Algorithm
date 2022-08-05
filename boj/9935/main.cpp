#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#endif  // gcc or not

using namespace std;
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s, del;
  cin >> s >> del;
  stack<char> stk;
  for (size_t i = 0; i < s.size(); ++i) {
    stk.push(s[i]);
  }
}

// 12ab112ab2ab
// 12a12abb