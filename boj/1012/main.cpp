#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

int M, N;
bitset<2601> visited;
struct Point {
  int row;
  int col;
};

bool isValidIdx(const Point &start) {
  return (start.col >= 0 && start.row >= 0) && (start.col < N && start.row < M);
}

void DFS(const Point &start, int *bat) {
  static const int rowIdx[] = {-1, 0, 0, 1};
  static const int colIdx[] = {0, -1, 1, 0};
  for (int i = 0; i < 4; ++i) {
    int row = start.row + rowIdx[i];
    int col = start.col + colIdx[i];
    if (isValidIdx({row, col}) && !visited[row + col * M] &&
        bat[row + col * M] == 1) {
      visited[row + col * M] = true;
      bat[row + col * M] = 0;
      DFS({row, col}, bat);
    }
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> M >> N >> K;
    int *bat = new int[(M + 1) * (N + 1)]{0};
    queue<Point> q;
    visited.reset();
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> x >> y;
      bat[x + y * M] = 1;
      q.push({x, y});
    }
    int cnt = 0;
    while (!q.empty()) {
      auto cur = q.front();
      if (bat[cur.row + cur.col * M] == 1) {
        DFS(q.front(), bat);
        ++cnt;
      }
      q.pop();
    }
    cout << cnt << "\n";
    delete[] bat;
  }
}