#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

inline list<int>* getBoard(const int highway) {
  list<int>* adj = new list<int>[101];
  vector<int> exist(101, 0);
  for (int i = 0; i < highway; ++i) {
    int a, b;
    cin >> a >> b;
    exist[a] = b;
  }
  for (int i = 1; i < 101; ++i) {
    if (exist[i]) continue;
    for (int j = 1; j < 7; ++j) {
      if (i + j <= 100) {
        if (exist[i + j] != 0)
          adj[i].push_back(exist[i + j]);
        else
          adj[i].push_back(i + j);
      }
    }
  }
  return adj;
}

vector<int> ret;
bool visited[101] = {
    0,
};

int dist = 0;
void BFS(list<int>* adj, int vertex, int start, int lv) {
  if (start > 100) {
    ret[100] = lv;
    return;
  }
  visited[start] = 1;
  for (auto& next : adj[start]) {
    if (visited[next] == 0 || lv < ret[next]) {
      visited[next] = 1;
      ret[next] = lv;
      BFS(adj, 100, next, lv + 1);
    }
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  list<int>* adj;
  ret.assign(101, 101);
  int ladder, snake;
  cin >> ladder >> snake;
  adj = getBoard(ladder + snake);
  adj[0].push_back(1);
  BFS(adj, 100, 1, 1);
  cout << ret[100] << "\n";

  delete[] adj;
}
