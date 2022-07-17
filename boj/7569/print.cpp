#include <iostream>
#include <list>
#include <queue>

using namespace std;
int tomatoes[100][100][100] = {0};

int heightIdx[6] = {-1, 0, 0, 0, 0, 1};
int rowIdx[6] = {0, -1, 0, 0, 1, 0};
int colIdx[6] = {0, 0, -1, 1, 0, 0};

struct Position {
  int row;
  int col;
  int height;
};

bool isValidIdx(const Position &pos, const Position &end) {
  return ((pos.row >= 0 && pos.col >= 0 && pos.height >= 0) &&
          (pos.row < end.row && pos.col < end.col && pos.height < end.height));
}

bool visited[101][101][101] = {false};

queue<Position> BFS(queue<Position> &starts, const Position &end) {
  queue<Position> q;
  while (!starts.empty()) {
    auto cur = starts.front();
    starts.pop();
    visited[cur.height][cur.col][cur.row] = true;
    for (int i = 0; i < 6; ++i) {
      int row = cur.row + rowIdx[i];
      int col = cur.col + colIdx[i];
      int height = cur.height + heightIdx[i];
      if (isValidIdx({row, col, height}, end) && !visited[height][col][row] &&
          tomatoes[height][col][row] == 0) {
        visited[height][col][row] = true;
        tomatoes[height][col][row] = 1;
        q.push({row, col, height});
      }
    }
  }
  return q;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int M, N, H;
  cin >> M >> N >> H;
  const Position end{M, N, H};
  queue<Position> q;
  int cnt = 0;
  int noPos = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        cin >> tomatoes[i][j][k];
        if (tomatoes[i][j][k] == 1)
          q.push({k, j, i});
        else if (tomatoes[i][j][k] == -1)
          ++noPos;
      }
    }
  }
  int day = -1;
  cnt = 0;
  while (!q.empty()) {
    ++day;
    cnt += q.size();
    cout << "q size : " << cnt << "\n";
    cout << cnt << "th day : \n";
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < M; ++k) {
          cout << "[" << tomatoes[i][j][k] << "]";
        }
        cout << endl;
      }
      cout << endl;
    }
    q = BFS(q, end);
  }
  cout << "day : " << day << " cnt : " << cnt << " noPos : " << noPos << "\n";
  if (cnt + noPos != M * N * H) cout << "NONONO\n";

  return 0;
}