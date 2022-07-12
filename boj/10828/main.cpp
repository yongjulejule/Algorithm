#include <iostream>
#include <stack>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  stack<int> st;
  while (N--) {
    string s;
    int nbr;
    cin >> s;
    if (s == "push") {
      cin >> nbr;
      st.push(nbr);
    } else if (s == "pop") {
      if (st.empty())
        cout << -1 << "\n";
      else {
        cout << st.top() << '\n';
        st.pop();
      }
    } else if (s == "top") {
      if (st.empty())
        cout << -1 << "\n";
      else
        cout << st.top() << '\n';
    } else if (s == "empty") {
      cout << st.empty() << '\n';
    } else if (s == "size") {
      cout << st.size() << '\n';
    }
  }
}