#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  stack<int> st;
  vector<int> v;
  v.reserve(N);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  vector<char> res;
  int cnt = 0;
  for (int i = 0; i <= N; ++i) {
    st.push(i);
    res.push_back('+');

    while (!st.empty() && st.top() == v[cnt]) {
      st.pop();
      res.push_back('-');
      ++cnt;
    }
  }
  if (st.empty()) {
    for_each(res.begin(), res.end(), [](char c) { cout << c << "\n"; });
  } else
    cout << "NO\n";
}