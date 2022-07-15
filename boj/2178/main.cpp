#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

struct queueNode {
  Point p;
  int dist;
};

bool isValid(const Point& p, const Point& end) {
  return p.x >= 0 && p.x < end.x && p.y >= 0 && p.y < end.y;
}

int BFS(vector<bool>* map, Point& end, Point& src, Point& dest) {
  if (map[src.x][src.y] == false || map[dest.x][dest.y] == false) return -1;
  bool visited[end.x][end.y];
  memset(visited, false, sizeof(visited));
  visited[src.x][src.y] = true;
  int rowNum[] = {-1, 0, 0, 1};
  int colNum[] = {0, -1, 1, 0};

  queue<queueNode> q;
  queueNode s = {src, 0};
  q.push(s);
  while (!q.empty()) {
    queueNode cur = q.front();
    Point pt = cur.p;
    if (pt.x == dest.x && pt.y == dest.y) return cur.dist;

    q.pop();
    for (int i = 0; i < 4; ++i) {
      int row = pt.x + rowNum[i];
      int col = pt.y + colNum[i];
      if (isValid({row, col}, end) && map[row][col] == true &&
          visited[row][col] == false) {
        visited[row][col] = true;
        queueNode n = {Point{row, col}, cur.dist + 1};
        q.push(n);
      }
    }
  }
  return -1;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  Point end = {N, M};
  vector<bool>* map = new vector<bool>[N];
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for_each(s.begin(), s.end(),
             [&map, &i](char& c) { map[i].push_back(c == '1'); });
  }
  Point src = {0, 0};
  Point dest = {N - 1, M - 1};
  int dist = BFS(map, end, src, dest);
  cout << dist + 1 << "\n";
  delete[] map;
}