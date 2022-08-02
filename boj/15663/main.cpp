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
bool visited[9];

void permutationDFS(int cur) {
  if (digits == cur) {
    for (int i = 0; i < digits; ++i) {
      cout << permutation[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = 0; i < N; ++i) {
    if (!visited[i] && tmp != base[i]) {
      tmp = base[i];
      permutation[cur] = base[i];
      visited[i] = true;
      permutationDFS(cur + 1);
      visited[i] = false;
    }
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
  permutationDFS(0);
}