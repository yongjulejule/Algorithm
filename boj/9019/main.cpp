#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
bool visited[10001];

inline int D(int start) {
  start <<= 1;
  if (start > 9999) start %= 10000;
  return start;
}

inline int S(int start) {
  start -= 1;
  if (start < 0) start = 9999;
  return start;
}

inline int L(int start) {
  start = (start % 1000) * 10 + start / 1000;
  return start;
}

inline int R(int start) {
  start = (start % 10) * 1000 + (start / 10);
  return start;
}

struct queueNode {
  int n;
  string s;
  queueNode(int nbr, string str) : n(nbr), s(str) {}
};

string BFS(int start, int end) {
  queue<queueNode> q;
  q.push({start, ""});
  visited[start] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.n == end) return cur.s;
    int next = D(cur.n);
    if (!visited[next]) {
      visited[next] = true;
      q.push({next, cur.s + 'D'});
    }
    next = S(cur.n);
    if (!visited[next]) {
      visited[next] = true;
      q.push({next, cur.s + 'S'});
    }
    next = L(cur.n);
    if (!visited[next]) {
      visited[next] = true;
      q.push({next, cur.s + 'L'});
    }
    next = R(cur.n);
    if (!visited[next]) {
      visited[next] = true;
      q.push({next, cur.s + 'R'});
    }
  }
  return "";
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  int start, end;
  while (tc--) {
    memset(visited, false, sizeof(visited));
    cin >> start >> end;
    cout << BFS(start, end) << '\n';
  }
}