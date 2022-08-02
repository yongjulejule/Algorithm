#if __GNUC__ && !__clang__

#include <bits/stdc++.h>

#else  // __clang__

#include <algorithm>
#include <iostream>

#endif  // gcc or not

using namespace std;

int permutation[9];
bool visited[9];
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
    if (!visited[i]) {
      visited[i] = true;
      permutation[cur] = i;
      permutationDFS(i + 1, cur + 1);
      visited[i] = false;
    }
  }
}
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> N >> digits;
  permutationDFS(1, 0);
}