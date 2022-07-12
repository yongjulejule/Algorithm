#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int c;
  cin >> c;
  while (c--) {
    int H, W, N;
    cin >> H >> W >> N;
    int mod = N % H, div = N / H;
    if (!mod) {
      mod = H;
      --div;
    }
    cout << 100 * mod + div + 1 << "\n";
  }
}