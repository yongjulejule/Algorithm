#include <algorithm>
#include <iostream>

int ans;

inline void D() {
  ans <<= 1;
  if (ans > 9999) ans %= 10000;
}

inline void S() {
  ans -= 1;
  if (ans < 0) ans = 9999;
}

inline void L() { ans = (ans % 1000) * 10 + ans / 1000; }

inline void R() { ans = (ans % 10) * 1000 + (ans / 10); }

using namespace std;
#include <unistd.h>
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ans = 1002;
}