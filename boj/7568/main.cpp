#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  deque<int *> dq;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    int *tmp = new int[4]{a, b, i, 0};
    dq.push_back(tmp);
  }
  int rank = 1, w, h;
  for (int i = 0; i < N; ++i) {
    h = dq[i][1];
    w = dq[i][0];
    int cnt = 1;
    for (int j = 0; j < N; ++j) {
      if (dq[j][1] > h && dq[j][0] > w) {
        ++cnt;
      }
    }
    dq[i][3] = cnt;
  }
  sort(dq.begin(), dq.end(),
       [](const int a[4], const int b[4]) { return a[2] < b[2]; });
  for (auto &a : dq) {
    cout << a[3] << " ";
  }
  cout << "\n";
}