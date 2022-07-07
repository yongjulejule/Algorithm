#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

string chess1[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                    "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string chess2[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                    "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int countRedrawSquare(string* s, int& row, int& col) {
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (s[i + row][j + col] != chess1[i][j]) ++cnt1;
      if (s[i + row][j + col] != chess2[i][j]) ++cnt2;
    }
  }
  return min(cnt1, cnt2);
}

int main() {
  int col, row;
  cin >> row >> col;

  string* s = new string[row];
  char tmp[1];
  cin.read(tmp, 1);
  for (int i = 0; i < row; ++i) {
    getline(cin, s[i]);
  }
  set<int> iSet;
  for (int i = 0; i <= row - 8; ++i) {
    for (int j = 0; j <= col - 8; ++j) {
      iSet.insert(countRedrawSquare(s, i, j));
    }
  }
  cout << *iSet.begin() << "\n";
  delete[] s;
  return 0;
}