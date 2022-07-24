#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int testCase;
  cin >> testCase;
  string ops, arr;
  int size;
  while (testCase--) {
    cin >> ops >> size >> arr;
    list<int> li;
    arr = arr.substr(1, arr.size() - 2);
    stringstream ss(arr);
    string element;
    while (!ss.eof()) {
      getline(ss, element, ',');
      if (element[0]) li.push_back(stoi(element));
    }
    bool error = false;
    bool reverse = false;
    for (auto &c : ops) {
      if (c == 'R') {
        reverse = !reverse;
      } else if (c == 'D') {
        if (li.empty()) {
          error = true;
          break;
        }
        if (reverse)
          li.pop_back();
        else
          li.pop_front();
      }
    }
    if (error)
      cout << "error\n";
    else {
      if (reverse) li.reverse();
      cout << '[';
      auto it = li.begin();
      auto ite = li.end();
      auto tmp = --li.end();
      for (; it != ite; ++it) {
        cout << *it;
        if (tmp != it) cout << ',';
      }
      cout << "]\n";
    }
    li.clear();
  }
}