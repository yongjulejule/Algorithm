#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int x, y, w, h;
  cin >> x >> y >> w >> h;
  int hori = w - x < x ? w - x : x;
  int vert = h - y < y ? h - y : y;
  cout << min(hori, vert) << "\n";
}