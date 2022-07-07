#include <iostream>
#include <string>

using namespace std;
int main() {
  while (true) {
    string s("");
    cin >> s;
    if (cin.bad() || cin.fail() || cin.eof() || s == "0") break;
    auto it = s.begin();
    auto ite = --s.end();
    bool flag = true;
    for (; it <= ite; ++it, --ite) {
      if (*it != *ite) {
        flag = false;
        break;
      }
    }
    flag ? cout << "yes"
                << "\n"
         : cout << "no"
                << "\n";
  }
  return 0;
}