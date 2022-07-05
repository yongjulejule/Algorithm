#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  size_t cnt = 0;
  size_t pos = 0;
  while (true) {
    pos = s.find(' ', pos + 1);
    if (pos == string::npos) break;
    ++cnt;
  }
  if (*(--s.end()) == ' ') --cnt;
  cout << cnt + 1 << "\n";
}