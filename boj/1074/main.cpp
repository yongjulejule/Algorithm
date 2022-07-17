#include <iostream>

using namespace std;

int N, x, y;
int ans = 0;

void genZ(int curX, int curY, int n) {
  if (curX == x && curY == y) {
    cout << ans << "\n";
    return;
  }
  if (x < curX + n && x >= curX && y < curY + n && y >= curY) {
    genZ(curX, curY, (n >> 1));
    genZ(curX, curY + (n >> 1), (n >> 1));
    genZ(curX + (n >> 1), curY, (n >> 1));
    genZ(curX + (n >> 1), curY + (n >> 1), (n >> 1));
  } else {
    ans += n * n;
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> x >> y;
  genZ(0, 0, 1 << N);
}