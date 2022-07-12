#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, K;
  cin >> N >> K;
  queue<int> q;
  vector<int> v;
  v.reserve(N);
  for (int i = 1; i <= N; ++i) {
    q.push(i);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j < K; ++j) {
      q.push(q.front());
      q.pop();
    }
    v.push_back(q.front());
    q.pop();
  }
  cout << "<";
  for (int i = 0; i < N - 1; ++i) {
    cout << v[i] << ", ";
  }
  cout << v[N - 1] << ">";
  return 0;
}