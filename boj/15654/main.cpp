#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>

#endif  // gcc or not

using namespace std;

int permutation[9];
int base[9];
int N, digits;

void permutationDFS(int seq, int cur) {
  if (digits == cur) {
    for (int i = 0; i < digits; ++i) {
      cout << permutation[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = seq; i <= N; ++i) {
    permutation[cur] = base[i];
    permutationDFS(i, cur + 1);
  }
}
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> N >> digits;
  for (int i = 0; i < N; ++i) {
    cin >> base[i];
  }
  sort(base, base + N);
  permutationDFS(1, 0);
}