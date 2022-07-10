#include <iostream>

using namespace std;

// int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// int main() {
//   cin.ios::sync_with_stdio(false);
//   cin.tie(0);
//   cout.tie(0);
//   int a, b;
//   cin >> a >> b;
//   int c = gcd(a, b);
//   int d = a * b / c;
//   cout << c << "\n" << d << "\n";
// }

#include <numeric>

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  int c = gcd(a, b);
  int d = lcm(a, b);

  cout << c << "\n" << d << "\n";
}