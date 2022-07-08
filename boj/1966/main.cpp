#include <iostream>
#include <queue>
#include <utility>

using namespace std;

inline void printer_queue(void) {
  queue<pair<int, int>> q;
  priority_queue<int> pq;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    int pri;
    cin >> pri;
    q.push(make_pair(i, pri));
    pq.push(pri);
  }
  int cnt = 0;
  while (!q.empty()) {
    int idx = q.front().first;
    int pri = q.front().second;
    q.pop();
    if (pq.top() == pri) {
      pq.pop();
      ++cnt;
      if (idx == M) {
        cout << cnt << "\n";
        break;
      }
    } else {
      q.push(make_pair(idx, pri));
    }
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  while (N--) {
    printer_queue();
  }
}