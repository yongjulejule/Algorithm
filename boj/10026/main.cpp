#include <cstdint>
#include <cstring>
#include <iostream>

using namespace std;
uint8_t RGB[100][100];
uint8_t RG[100][100];
bool visited[100][100];
int cntRGB = 0;
int cntRG = 0;
int Size;

const int rowIdx[4] = {1, 0, 0, -1};
const int colIdx[4] = {0, 1, -1, 0};

bool isValidIdx(int row, int col) {
  return (row >= 0 && row < Size) && (col >= 0 && col < Size);
}

void DFSRGB(int row, int col) {
  visited[row][col] = true;
  auto curColor = RGB[row][col];
  for (int i = 0; i < 4; ++i) {
    int curRow = row + rowIdx[i];
    int curCol = col + colIdx[i];
    if (isValidIdx(curRow, curCol) && !visited[curRow][curCol] &&
        curColor == RGB[curRow][curCol]) {
      DFSRGB(curRow, curCol);
    }
  }
}
void DFSRG(int row, int col) {
  visited[row][col] = true;
  auto curColor = RG[row][col];
  for (int i = 0; i < 4; ++i) {
    int curRow = row + rowIdx[i];
    int curCol = col + colIdx[i];
    if (isValidIdx(curRow, curCol) && !visited[curRow][curCol] &&
        curColor == RG[curRow][curCol]) {
      DFSRG(curRow, curCol);
    }
  }
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> Size;
  uint8_t color;
  for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
      cin >> color;
      if (color == 'R') {
        RGB[i][j] = RG[i][j] = 'R';
      } else if (color == 'B') {
        RGB[i][j] = RG[i][j] = 'B';
      } else {
        RGB[i][j] = 'G';
        RG[i][j] = 'R';
      }
    }
  }
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
      if (!visited[i][j]) {
        DFSRGB(i, j);
        ++cntRGB;
      }
    }
  }
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
      if (!visited[i][j]) {
        DFSRG(i, j);
        ++cntRG;
      }
    }
  }
  cout << cntRGB << ' ' << cntRG << '\n';
}