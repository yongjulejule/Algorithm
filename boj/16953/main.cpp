#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#endif  // gcc or not

using namespace std;

bitset<1000000001U> visited;
int64_t src, dst;

struct Node {
  int64_t val;
  int64_t dist;
};

inline bool isValid(int64_t idx) { return (src <= idx && idx <= 1000000001U); }

int64_t BFS(int64_t start, int64_t end) {
  queue<Node> q;
  q.push({start, 1});
  visited[start] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    auto op1 = cur.val * 2;
    auto op2 = cur.val * 10 + 1;
    if (op1 == end || op2 == end) return cur.dist + 1;
    if (isValid(op1) && !visited[op1]) {
      visited[op1] = true;
      q.push({op1, cur.dist + 1});
    }
    if (isValid(op2) && !visited[op2]) {
      visited[op2] = true;
      q.push({op2, cur.dist + 1});
    }
  }
  return -1;
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> src >> dst;
  cout << BFS(src, dst);
}