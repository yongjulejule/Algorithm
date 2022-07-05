#include <iostream>
#include <string>

using namespace std;

int main() {
  int i1, i2;
  cin >> i1 >> i2;
  (i1 > i2) ? cout << ">" : (i1 < i2) ? cout << "<" : cout << "==";
  cout << "\n";
  return 0;
}