#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#endif  // gcc or not

using namespace std;

list<int> adj[100001];
bool vis[100001];
int ans[100001];

void BFS(list<int> adj[], int size) {
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (auto& next : adj[cur]) {
      if (!vis[next]) {
        vis[next] = true;
        ans[next] = cur;
        q.push(next);
      }
    }
  }
  for (int i = 2; i < size; ++i) {
    cout << ans[i] << '\n';
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int N;
  cin >> N;
  list<int> adj[N + 1];
  for (int i = 0, a, b; i < N; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  BFS(adj, N + 1);
}