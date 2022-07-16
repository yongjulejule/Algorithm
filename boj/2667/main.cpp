#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int rowNum[] = {-1, 0, 0, 1};
const int colNum[] = {0, -1, 1, 0};

void BFS(vector<vector<int> > &map, pair<int, int> start, const int size) {
  static int num = 2;
  queue<pair<int, int> > q;
  q.push(start);
  map[start.first][start.second] = num;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int row = cur.first + rowNum[i];
      int col = cur.second + colNum[i];
      if (row >= 0 && row < size && col >= 0 && col < size &&
          map[row][col] == 1) {
        map[row][col] = num;
        q.push({row, col});
      }
    }
  }
  ++num;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<vector<int> > map(N);
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for_each(s.begin(), s.end(), [&](char c) { map[i].push_back(c - '0'); });
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] == 1) {
        BFS(map, {i, j}, N);
        ++cnt;
      }
    }
  }
  cout << cnt << "\n";
  int *ans = new int[cnt]{};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] > 1) {
        ++ans[map[i][j] - 2];
      }
    }
  }
  sort(ans, ans + cnt);
  for (int i = 0; i < cnt; ++i) {
    cout << ans[i] << "\n";
  }
  delete[] ans;

  return 0;
}
