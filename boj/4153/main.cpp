#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    float side[3];
    cin >> side[0] >> side[1] >> side[2];
    if (side[0] + side[1] + side[2] == 0) break;
    sort(side, side + 3);
    if (pow(side[0], 2) + pow(side[1], 2) == pow(side[2], 2)) {
      cout << "right\n";
    } else
      cout << "wrong\n";
  }
}