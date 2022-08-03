#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <stack>
#endif  // gcc or not

using namespace std;

int postIdx, post[100001], in[100001];

void insertPre(int inStart, int inEnd, stack<int> &s, int N) {
  if (inStart > inEnd) return;

  int val = post[postIdx--];
  int inIdx = in[val];
  insertPre(inIdx + 1, inEnd, s, N);
  insertPre(inStart, inIdx - 1, s, N);
  s.push(val);
}

void preOrder(const int N) {
  postIdx = N - 1;
  stack<int> s;
  insertPre(0, N - 1, s, N);
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0, val; i < N; ++i) {
    cin >> val;
    in[val] = i;
  }
  for (int i = 0; i < N; ++i) {
    cin >> post[i];
  }
  preOrder(N);
}