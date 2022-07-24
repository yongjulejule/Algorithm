#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

inline int countPress(int dest, bool buttons[]) {
  if (!dest) return buttons[0] ? 1 : 0;
  int ret = 0;
  while (dest > 0) {
    if (!buttons[dest % 10]) return 0;
    dest /= 10;
    ++ret;
  }
  return ret;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int M;
  int dest;
  cin >> dest >> M;
  bool buttons[10];
  memset(buttons, true, 10);
  for (int i = 0; i < M; ++i) {
    int nbr;
    cin >> nbr;
    buttons[nbr] = false;
  }
  int min = 0, max = 9;
  while (!buttons[min] && min < 9) ++min;
  while (!buttons[max] && max > 0) --max;
  int len = 0, tmp = dest;
  while (tmp) {
    ++len;
    tmp /= 10;
  }
  int lb = min;
  for (int i = 0; i < len - 2; ++i) {
    if (!i && !min) lb = 1;
    lb = 10 * lb + min;
  }
  int ub = max;
  for (int i = 0; i < len + 1; ++i) {
    if (!i && !max) ub = 9;
    ub = 10 * ub + max;
  }
  if (ub > 1000000) ub = 1000001;
  int res = abs(dest - 100);
  for (int i = lb; i < ub; ++i) {
    int cnt = countPress(i, buttons);
    if (cnt > 0) {
      int press = abs(i - dest);
      if (res > press + cnt) {
        res = press + cnt;
      }
    }
  }
  cout << res << '\n';
  return 0;
}