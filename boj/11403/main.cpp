#include <algorithm>
#include <iostream>

using namespace std;
#define INF 4242
int adj[100][100];
int ans[100][100];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cin >> adj[i][j];
      if (!adj[i][j]) adj[i][j] = INF;
    }
  }

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cout << (adj[i][j] != INF) << ' ';
    }
    cout << '\n';
  }
}