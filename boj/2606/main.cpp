#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int BFS(list<int>* adj, int vertex, int start) {
  bool visited[vertex + 1];
  memset(visited, false, vertex + 1);
  visited[start] = true;
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto& next : adj[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < vertex + 1; ++i) {
    if (visited[i]) ++cnt;
  }
  return cnt;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int vertex, edge;
  cin >> vertex >> edge;
  list<int>* adj = new list<int>[vertex + 1];
  for (int i = 1; i <= edge; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int cnt = BFS(adj, vertex, 1);
  cout << cnt - 1 << "\n";
  delete[] adj;
}