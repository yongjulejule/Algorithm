#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int a[5];
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
  transform(a, a + 5, a, [](int x) { return x * x; });
  int b = (a[0] + a[1] + a[2] + a[3] + a[4]) % 10;
  cout << b << "\n";
  return 0;
}