#include <algorithm>
#include <iostream>
using namespace std;
struct pt {
  int fs;
  int se;
};
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  pt mt[N];
  for (int i = 0; i < N; ++i) {
    cin >> mt[i].fs >> mt[i].se;
  }
  sort(mt, mt + N, [](pt &a, pt &b) {
    return (a.fs < b.fs) ? true : a.fs == b.fs ? a.se < b.se : false;
  });
  int n = 1;
  int u = mt[0].se;
  for (int i = 1; i < N; ++i) {
    if (mt[i].fs < u && u <= mt[i].se) continue;
    if (u <= mt[i].fs) ++n;
    u = mt[i].se;
  }
  cout << n;
}