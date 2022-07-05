#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  cout << stoi(s1) - stoi(s2);
  return 0;
}