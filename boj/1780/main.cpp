#include <cstring>
#include <iostream>

using namespace std;
int arr[2188][2188];
int cnt[3];

void countPaper(int row, int col, int size) {
  int cur = arr[row][col];
  bool valid = true;
  for (int i = 0; i < size && valid; ++i) {
    for (int j = 0; j < size && valid; ++j) {
      if (cur != arr[row + i][col + j]) {
        size /= 3;
        countPaper(row, col, size);
        countPaper(row + size, col, size);
        countPaper(row + size * 2, col, size);
        countPaper(row, col + size, size);
        countPaper(row, col + size * 2, size);
        countPaper(row + size, col + size, size);
        countPaper(row + size * 2, col + size, size);
        countPaper(row + size, col + size * 2, size);
        countPaper(row + size * 2, col + size * 2, size);
        valid = false;
      }
    }
  }
  if (valid) ++cnt[cur + 1];
}
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      cin >> arr[i][j];
    }
  }
  countPaper(0, 0, size);
  cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
}