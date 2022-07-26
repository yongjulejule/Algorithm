#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool image[64][64];
string ans;

void recursion(int row, int col, int size) {
  auto cur = image[row][col];
  bool valid = true;
  for (int i = row; i < size + row && valid; ++i) {
    for (int j = col; j < size + col && valid; ++j) {
      if (cur != image[i][j]) {
        valid = false;
        ans += '(';
        int newSize = size / 2;
        recursion(row, col, newSize);
        recursion(row, col + newSize, newSize);
        recursion(row + newSize, col, newSize);
        recursion(row + newSize, col + newSize, newSize);
        ans += ')';
      }
    }
  }
  if (valid) {
    ans += (cur + '0');
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int size;
  cin >> size;
  string buf;
  getline(cin, buf);
  for (int i = 0; i < size; ++i) {
    getline(cin, buf);
    for (int j = 0; j < size; ++j) {
      image[i][j] = (buf[j] == '1');
    }
  }
  recursion(0, 0, size);
  cout << ans;
}