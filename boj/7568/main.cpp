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
  sort(dq.begin(), dq.end(),
       [](const int a[4], const int b[4]) { return (a[0] > b[0]); });
  int rank = 1, w = (*dq.begin())[0], h = (*dq.begin())[1];
  int idx = 2;
  (*dq.begin())[3] = 1;
  for (int i = 0; i < N; ++i) {
    h = dq[i][1];
    for (int k = 0; k < N; ++k)
      cout << "dq[k][0] : " << dq[k][0] << " dq[k][1] : " << dq[k][1]
           << " dq[k][2] : " << dq[k][2] << " dq[k][3] : " << dq[k][3] << endl;
    for (int j = i; j < N; ++j) {
      // cout << "dq[j][0] : " << dq[j][0] << " dq[j][1] : " << dq[j][1]
      //      << " dq[j][2] : " << dq[j][2] << " dq[j][3] : " << dq[j][3] <<
      //      endl;
      if (dq[j][3] != 0) {
        ++idx;
        continue;
      }
      if (dq[j][1] > h) dq[j][3] = rank;
    }
    rank = idx + 1;
    cout << "===============\n";
  }
  sort(dq.begin(), dq.end(),
       [](const int a[4], const int b[4]) { return a[2] < b[2]; });
  cout << "=============================\n";
  for (auto &a : dq) {
    cout << "a[0] : " << a[0] << " a[1] : " << a[1] << " a[2] : " << a[2]
         << " a[3] : " << a[3] << endl;
    // cout << a[3] << " ";
  }
  cout << "\n";
}