#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
stringstream ss;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bool set[21];
  memset(set, false, 21);
  int N;
  cin >> N;
  int n = 0;
  while (N--) {
    string s;
    int num;
    cin >> s;
    if (s[1] == 'd') {
      cin >> num;
      set[num] = true;
    } else if (s[0] == 'r') {
      cin >> num;
      set[num] = false;
    } else if (s[0] == 'c') {
      cin >> num;
      ss << set[num] << '\n';
    } else if (s[0] == 't') {
      cin >> num;
      set[num] = set[num] ? false : true;
    } else if (s[1] == 'l') {
      memset(set, true, 21);
    } else if (s[0] == 'e') {
      memset(set, false, 21);
    }
    if (n > 8000) {
      n = 0;
      cout << ss.str();
      ss.str("");
    }
    ++n;
  }
  cout << ss.str();
  return 0;
}