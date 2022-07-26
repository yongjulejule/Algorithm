#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int ocean[20][20];
bool visited[20][20];
int len;
int fishes = 0;
struct Point {
  int row;
  int col;
};

vector<pair<Point, int> > candidates;

struct BabyShark {
  Point pos;
  int weight;
  int ate;
  int total;
  int sec;
  BabyShark() {}
  BabyShark(Point p, int w) : pos(p), weight(w) {}
  void operator()(Point p, int w, int s, int a) {
    pos = p, weight = w, sec = s, ate = a, total = 0;
  }
  void eatOneFish() {
    ++ate;
    ++total;
    if (ate == weight) {
      ++weight;
      ate = 0;
    }
  }
};

bool isValidIdx(int row, int col) {
  return (0 <= row && row < len) && (0 <= col && col < len);
}

bool BFS(BabyShark& shark) {
  const static int rowIdx[4] = {-1, 0, 0, 1};
  const static int colIdx[4] = {0, -1, 1, 0};
  queue<pair<Point, int> > q;
  q.push({shark.pos, 0});
  visited[shark.pos.row][shark.pos.col] = true;
  int maxDist = 9999;
  while (!q.empty()) {  // 어케 종료시키지?
    auto cur = q.front();
    if (maxDist <= cur.second) return true;

#ifndef BOJ
    cout << "row : " << cur.first.row << " col : " << cur.first.col
         << " sec : " << cur.second << " max dist : " << maxDist << '\n';

#endif
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int row = cur.first.row + rowIdx[i];
      int col = cur.first.col + colIdx[i];
      if (isValidIdx(row, col) && !visited[row][col] &&
          ocean[row][col] <= shark.weight) {
        if (shark.weight > ocean[row][col] && ocean[row][col] > 0) {
          // 여기서 후보에 담아야 함... 그리고 거리가 더 멀어지면 끝나는데
          // 조건을 어케줌?

          // shark.pos = {row, col};
          // shark.sec += cur.second + 1;

          candidates.push_back(
              {{row, col},
               cur.second + 1});  // row가 젤 작은거, 같으면 col이 가장 큰거
          maxDist = cur.second + 1;
          // shark.eatOneFish();
          ocean[row][col] = -1;
          // return true;
        } else {
          visited[row][col] = true;
          q.push({{row, col}, cur.second + 1});
        }
      }
    }
  }
  return !candidates.empty();
}

void applyResult(BabyShark& shark, pair<Point, int>& v) {
  shark.pos = v.first;
  shark.sec += v.second;
  shark.eatOneFish();
  ocean[v.first.row][v.first.col] = 0;
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> len;
  BabyShark shark;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      cin >> ocean[i][j];
      if (ocean[i][j] == 9) {
        shark({i, j}, 2, 0, 0);
        ocean[i][j] = 0;
      } else if (ocean[i][j]) {
        ++fishes;
      }
    }
  }
  if (!fishes) {
    cout << '0';
    return 0;
  }

  while (fishes != shark.total) {
    if (!BFS(shark)) break;

#ifndef BOJ
    for (auto& c : candidates) {
      cout << "Candidates : row : " << c.first.row << " col : " << c.first.col
           << " second : " << c.second << '\n';
    }
#endif

    for (auto& p : candidates) {
      ocean[p.first.row][p.first.col] = 1;
    }
    applyResult(shark, *min_element(candidates.begin(), candidates.end(),
                                    [](auto& a, auto& b) {
                                      return (a.first.row < b.first.row) ? true
                                             : (a.first.row == b.first.row)
                                                 ? a.first.col < b.first.col
                                                 : false;
                                    }));
    candidates.clear();
    memset(visited, false, sizeof(visited));

#ifndef BOJ
    cout << "shark's pos : <" << shark.pos.row << ", " << shark.pos.col
         << "> weight : " << shark.weight << " ate : " << shark.ate
         << " sec : " << shark.sec << '\n';
    cout << "ocean info :\n";
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (shark.pos.row == i && shark.pos.col == j) {
          cout << "\033[31m";
        }
        cout << ocean[i][j] << " ";
        if (shark.pos.row == i && shark.pos.col == j) {
          cout << "\033[0m";
        }
      }
      cout << endl;
    }
    cout << "\n==========================\n";

#endif
  }

  cout << shark.sec << '\n';
}