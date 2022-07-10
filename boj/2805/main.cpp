#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
using uint = unsigned int;

inline uint getTreeHeight(uint *tree, uint N, uint height) {
  uint sum = 0;
  for_each(tree, tree + N, [&](uint x) {
    if (x > height) sum += x - height;
  });
  return sum;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  uint N, M;
  cin >> N >> M;
  uint *tree = new uint[N];
  for_each(tree, tree + N, [](uint &x) { cin >> x; });
  sort(tree, tree + N);
  uint h = tree[N - 1];
  uint ub = h, lb = h - M;
  while (lb + 1 < ub) {
    h = (lb + ub) / 2;
    uint ret = getTreeHeight(tree, N, h);
    if (M < ret) {
      lb = h;
    } else if (M > ret) {
      ub = h;
    } else
      break;
  }
  cout << h << "\n";
}