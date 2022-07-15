#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

template <typename vertex_type = int>
class Graph {
 private:
  using T = vertex_type;
  T _v;
  list<T> *_adj;

 public:
  Graph() : _v(0), _adj(nullptr) {}
  Graph(T v) : _v(v + 1), _adj(new list<T>[_v]) {}
  Graph(const Graph &g) {
    if (g.adj != nullptr) {
      delete[] _adj;
      _adj = new list<T>[g._v];
      for (int i = 0; i < g._v; ++i) {
        _adj[i](g._adj[i]);
      }
      _v = g._v;
    }
  }
  Graph &operator=(const Graph &g) {
    if (g._adj != nullptr) {
      delete[] _adj;
      _adj = new list<T>[g._v];
      for (int i = 0; i < g._v; ++i) {
        _adj[i](g._adj[i]);
      }
      _v = g._v;
    }
    return *this;
  }
  Graph &operator=(Graph &&g) {
    if (_adj != nullptr) delete[] _adj;
    _v = g._v;
    _adj = g._adj;
    g._v = 0;
    g._adj = nullptr;
  }
  Graph(Graph &&g) : _v(g._v) {
    delete[] _adj;
    _adj = g._adj;
    g._v = 0;
    g._adj = nullptr;
  }

  ~Graph() { delete[] _adj; }

  void addEdge(T v, T w) {
    _adj[v].push_back(w);
    _adj[w].push_back(v);
  }
  void sortGraph() {
    for (int i = 1; i < _v; ++i) {
      _adj[i].sort();
    }
  }
  T getVertex() const { return _v; }
  list<T> getAdj(T v) const { return _adj[v]; }
  vector<int> DFS(T v) const {
    vector<int> visited(_v, 0);
    vector<int> order;
    DFS(v, visited, order);
    return order;
  }
  vector<int> DFS(T v, vector<int> &visited, vector<int> &order) const {
    visited[v] = 1;
    order.push_back(v);
    for (auto &w : _adj[v]) {
      if (!visited[w]) {
        DFS(w, visited, order);
      }
    }
    return order;
  }
  vector<int> BFS(T v) const {
    vector<bool> visited(_v, false);
    vector<int> ret;
    ret.reserve(_v);
    queue<T> q;
    q.push(v);
    visited[v] = true;
    ret.push_back(v);
    while (!q.empty()) {
      T u = q.front();
      q.pop();
      for (auto &w : _adj[u]) {
        if (!visited[w]) {
          q.push(w);
          visited[w] = true;
          ret.push_back(w);
        }
      }
    }
    return ret;
  }
};

template <typename T>
ostream &operator<<(ostream &os, const Graph<T> &g) {
  for (int i = 0; i < g.getVertex(); ++i) {
    os << "[" << i << "]";
    for (auto j : g.getAdj(i)) {
      os << " -> [" << j << "]";
    }
    os << " -> [\\] \n";
  }
  return os;
}

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
  cout << g << "\n";
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

  return 0;
}