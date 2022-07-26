#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

inline int getYears(int m1, int m2, int v1, int v2, const int last) {
  int ret = v1;
  while (ret <= last) {
    if ((ret % m1) == (v1 % m1) && (ret % m2) == (v2 % m2)) {
      break;
    }
    ret += m1;
  }
  if (ret > last) return -1;
  return ret;
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int testCase;
  cin >> testCase;
  int M, N, x, y;
  while (testCase--) {
    cin >> M >> N >> x >> y;
    const int last = lcm(M, N);
    cout << (M > N ? getYears(M, N, x, y, last) : getYears(N, M, y, x, last))
         << '\n';
  }
}

// 10 => <10 mod 10, 10 mod 12>
// 11 => <11 mod 10 , 11 mod 12>
// 13 => <13 mod 10, 13 mod 12>

// 60 => <60 mod 10, 60 mod 12> => 최소공배수가 마지막임
// 59 => <59 mod 10, 59 mod 12> => <9, 11>
// 58 => <58 mod 10, 58 mod 12> => <8, 10>

// 33 => <33 mod 10, 33 mod 12> => <3, 9>

// 83 => <83 mod 13, 83 mod 11> => <5, 6>
