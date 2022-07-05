#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  cout.precision(15);
  cout << stod(s1) / stod(s2);
  return 0;
}