#include <cmath>
#include <iostream>

// 점화식 1 + 6 * 1 + 6 * 2 + 6 * 3 ...  6 * (n - 1) = 1 + 3 * (n - 1) * n
//  => 1 + 3 * (n - 2) * (n - 1) < x <= 1 + 3 * (n - 1) * n
// =>  n - 2 <  x - 1 / (3 *(n - 1)) <= n
// => (x - 1) / 3 <= n * (n - 1) <= n^2
// => sqrt(x - 1 / 3) <= sqrt(n * (n - 1)) <= n
using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin >> x;
  if (x <= 7) {
    cout << ((x == 1) ? 1 : 2) << "\n";
    return 0;
  }
  double num = static_cast<float>(x - 1) / 3;
  int n = 1;
  while (n * (n - 1) < num) {
    n++;
  }
  cout << floor(n) << "\n";
}