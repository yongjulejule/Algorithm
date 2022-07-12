#include <deque>
#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  deque<int> q;
  while (N--) {
    string s;
    int nbr;
    cin >> s;

    if (s == "push_front") {
      cin >> nbr;
      q.push_front(nbr);
    } else if (s == "push_back") {
      cin >> nbr;
      q.push_back(nbr);
    } else if (s == "pop_back") {
      if (q.empty())
        cout << -1 << "\n";
      else {
        cout << q.back() << '\n';
        q.pop_back();
      }
    } else if (s == "pop_front") {
      if (q.empty())
        cout << -1 << "\n";
      else {
        cout << q.front() << '\n';
        q.pop_front();
      }
    } else if (s == "front") {
      if (q.empty())
        cout << -1 << "\n";
      else
        cout << q.front() << '\n';
    } else if (s == "back") {
      if (q.empty())
        cout << -1 << "\n";
      else
        cout << q.back() << '\n';
    } else if (s == "empty") {
      cout << q.empty() << '\n';
    } else if (s == "size") {
      cout << q.size() << '\n';
    }
  }
}