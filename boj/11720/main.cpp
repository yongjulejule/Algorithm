#include <iostream>
#include <string>

using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  n = 0;
  for (char &c : s) {
    n += c - '0';
  }
  cout << n << "\n";
}