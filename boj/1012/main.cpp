#include <iostream>

using namespace std;

int getAdjBaechu(int *bat, const int w, const int h, const int i, const int j) {
  int count = 0;
  count = bat[i * w + j];

  return count;
}

void putJiRungI(int *bat, const int w, const int h) {
  for (int i = 1; i < w - 1; ++i) {
    for (int j = 1; j < h - 1; ++j) {
    }
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int M, N, K;
    cin >> M >> N >> K;
    int *bat = new int[M * N];
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> x >> y;
      bat[x + y * M] = 1;
    }
    putJiRungI(bat, M, N);
    for (int i = 0; i < N * M; ++i) {
      cout << bat[i] << ", ";
      if (i % M == M - 1) cout << endl;
    }

    delete[] bat;
    cout << "======================\n";
  }
}