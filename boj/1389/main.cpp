#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int ans[101];
list<int> adj[101];
bool visited[101];

struct Pair {
  int user;
  int dist;
};

void BFS(int people) {
  visited[people] = true;
  queue<Pair> q;
  q.push({people, 0});
  while (!q.empty()) {
    auto cur = q.front();
    ans[people] += cur.dist;
    int dist = cur.dist + 1;
    q.pop();
    for (auto &next : adj[cur.user]) {
      if (!visited[next]) {
        visited[next] = true;
#ifndef BOJ
        cout << "cur people : " << people << " dist : " << dist
             << " next : " << next << '\n';
#endif
        q.push({next, dist});
      }
    }
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int users, friends;
  cin >> users >> friends;
  for (int i = 0; i < friends; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= users; ++i) {
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    BFS(i);
  }
  cout << min_element(ans + 1, ans + users + 1) - ans;
}