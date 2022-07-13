#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int cntMiningBlocks(int *lend, int height, int size) {
  int cnt = 0;
  for (int i = 0; i < size; ++i) {
    if (lend[i] > height) cnt += lend[i] - height;
  }
  return cnt;
}

int cntShortageBlocks(int *lend, int height, int size) {
  int cnt = 0;
  for (int i = 0; i < size; ++i) {
    if (lend[i] < height) cnt += height - lend[i];
  }
  return cnt;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  int B;
  cin >> N >> M >> B;
  const int size = N * M;
  int *lend = new int[size];
  for_each(lend, lend + size, [](int &x) { cin >> x; });
  auto minmax = minmax_element(lend, lend + size);

  if (*minmax.first == *minmax.second) {
    cout << "0 " << *minmax.first << "\n";
    return 0;
  }
  vector<pair<int, int> > ans;
  ans.reserve(*minmax.second - *minmax.first + 1);
  for (int i = *minmax.second; i >= *minmax.first; --i) {
    int ops = 0;
    int miningBlocks = cntMiningBlocks(lend, i, size);
    int shortageBlocks = cntShortageBlocks(lend, i, size);
    if (miningBlocks + B < shortageBlocks) continue;
    ops = shortageBlocks + 2 * miningBlocks;
    ans.push_back({ops, i});
  }
  auto res =
      min_element(ans.begin(), ans.end(),
                  [](const pair<uint, uint> &a, const pair<uint, uint> &b) {
                    return a.first < b.first;
                  });
  cout << res->first << " " << res->second << "\n";
  delete[] lend;
}
