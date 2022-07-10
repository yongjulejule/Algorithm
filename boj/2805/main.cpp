#include <algorithm>
#include <iostream>

using namespace std;

inline long long getTreeHeight(long long *tree, long long N, long long height) {
  long long sum = 0;
  for_each(tree, tree + N, [&](long long x) {
    if (x > height) sum += x - height;
  });
  return sum;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, M;
  cin >> N >> M;
  long long *tree = new long long[N];
  for_each(tree, tree + N, [](long long &x) { cin >> x; });
  long long h;
  long long ub = *max_element(tree, tree + N), lb = 0;
  int ans = -1;
  while (lb <= ub) {
    h = (lb + ub) / 2;
    long long ret = getTreeHeight(tree, N, h);
    if (ret >= M) {
      ans = h;
      lb = h + 1;
    } else {
      ub = h - 1;
    }
  }
  cout << ans << "\n";
  delete[] tree;
}