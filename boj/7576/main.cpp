#include <iostream>
#include <queue>

using namespace std;
int tomatoes[1001][1001] = {0};

const int rowIdx[4] = {-1, 0, 0, 1};
const int colIdx[4] = {0, -1, 1, 0};

struct Position {
  int row;
  int col;
};

bool isValidIdx(const Position &pos, const Position &end) {
  return ((pos.row >= 0 && pos.col >= 0) &&
          (pos.row < end.row && pos.col < end.col));
}

bool visited[1001][1001] = {false};

queue<Position> BFS(queue<Position> &starts, const Position &end) {
  queue<Position> q;
  while (!starts.empty()) {
    auto cur = starts.front();
    starts.pop();
    visited[cur.col][cur.row] = true;
    for (int i = 0; i < 4; ++i) {
      int row = cur.row + rowIdx[i];
      int col = cur.col + colIdx[i];
      if (!visited[col][row] && !tomatoes[col][row] &&
          isValidIdx({row, col}, end)) {
        visited[col][row] = true;
        tomatoes[col][row] = 1;
        q.push({row, col});
      }
    }
  }
  return q;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int M, N;
  cin >> M >> N;
  const Position end{M, N};
  queue<Position> q;
  int noPos = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> tomatoes[i][j];
      if (tomatoes[i][j] == 1)
        q.push({j, i});
      else if (tomatoes[i][j] == -1)
        ++noPos;
    }
  }
  int day = -1;
  int cnt = 0;
  while (!q.empty()) {
    ++day;
    cnt += q.size();
    q = BFS(q, end);
  }
  if (cnt + noPos != M * N)
    cout << "-1\n";
  else
    cout << day << "\n";

  return 0;
}