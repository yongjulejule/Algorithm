#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#endif  // gcc or not

#define INF 0x01010101

using namespace std;
int cities[101][101];

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int nCities, nBuses;
  cin >> nCities >> nBuses;
  memset(cities, 0x01, sizeof(cities));  // INF=0x01010101
  for (int i = 1; i <= nCities; ++i) {
    cities[i][i] = 0;
  }
  for (int i = 1, src, dst, val; i <= nBuses; ++i) {
    cin >> src >> dst >> val;
    cities[src][dst] = min(cities[src][dst], val);
  }

  for (int i = 1; i <= nCities; ++i) {
    for (int j = 1; j <= nCities; ++j) {
      for (int k = 1; k <= nCities; ++k) {
        cities[j][k] = min(cities[j][k], cities[j][i] + cities[i][k]);
      }
    }
  }
  for (int i = 1; i <= nCities; ++i) {
    for (int j = 1; j <= nCities; ++j) {
      cout << ((cities[i][j] == INF) ? 0 : cities[i][j]) << ' ';
    }
    cout << '\n';
  }
}
