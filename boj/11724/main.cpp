#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

bool visited[1001];
vector<list<int> > vertex;

void DFS(int& start) {
  visited[start] = true;
  for (auto& next : vertex[start])
    if (!visited[next]) DFS(next);
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e;
  cin >> v >> e;
  vertex.reserve(v);
  int a, b;
  for (int i = 0; i < e; ++i) {
    cin >> a >> b;
    vertex[a].push_back(b);
    vertex[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 1; i <= v; ++i) {
    if (!visited[i]) {
      DFS(i);
      ++cnt;
    }
  }
  cout << cnt;
}