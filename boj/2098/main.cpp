#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  lexicographical_compare(a.rbegin(), a.rend(), b.rbegin(), b.rend())
      ? cout << b[2] << b[1] << b[0]
      : cout << a[2] << a[1] << a[0];

  return 0;
}