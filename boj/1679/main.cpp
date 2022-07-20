#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
bool visited[100001];
queue<int> BFS(queue<int> &start, int &cur, int end) {
  queue<int> q;
  while (!start.empty()) {
    cur = start.front();
    start.pop();
    if (cur == end) {
      break;
    }
    if (cur > 0 && !visited[cur - 1]) {
      q.push(cur - 1);
      visited[cur - 1] = true;
    }
    if (cur < 100000 && !visited[cur + 1]) {
      q.push(cur + 1);
      visited[cur + 1] = true;
    }
    if (cur < 50001 && !visited[cur * 2]) {
      q.push(cur * 2);
      visited[cur * 2] = true;
    }
  }
  return q;
}
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int start, end;
  cin >> start >> end;
  queue<int> q;
  q.push(start);
  visited[start] = true;
  int dist = 0;
  int cur = start;
  while (true) {
    q = BFS(q, cur, end);
    if (cur == end) break;
    ++dist;
  }
  cout << dist;
}