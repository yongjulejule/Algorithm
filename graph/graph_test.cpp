
#include "Graph.hpp"

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int vertex, edge, start;
  cin >> vertex >> edge >> start;
  Graph<int> g(vertex);
  for (int i = 0; i < edge; ++i) {
    int a, b;
    cin >> a >> b;
    g.addEdge(a, b);
  }
  g.sortGraph();
  vector<int> ret = g.DFS(start);
  for (auto &i : ret) {
    cout << i << " ";
  }
  cout << "\n";
  ret = g.BFS(start);
  for (auto &i : ret) {
    cout << i << " ";
  }
  cout << "\n";
  atexit([]() { system("leaks a.out"); });

  return 0;
}