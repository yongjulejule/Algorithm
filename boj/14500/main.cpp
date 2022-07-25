#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int maximum = 0;
int Board[500][500];
int w, h;

// ----
inline void IHorizon(int row, int col) {
  if (col + 3 < w) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
              Board[row][col + 3];
    if (maximum < num) {
      maximum = num;
    }
  }
}

// |
inline void IVertical(int row, int col) {
  if (row + 3 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 2][col] +
              Board[row + 3][col];
    if (maximum < num) {
      maximum = num;
    }
  }
}

// ㅁ
inline void Square(int row, int col) {
  if (col + 1 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row][col + 1] +
              Board[row + 1][col + 1];
    if (maximum < num) {
      maximum = num;
    }
  }
}
// L
inline void LFirst(int row, int col) {
  int num = Board[row][col] + Board[row + 1][col] + Board[row + 2][col] +
            Board[row + 2][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}
// _|
inline void LFirstMirror(int row, int col) {
  int num = Board[row][col + 1] + Board[row + 1][col + 1] +
            Board[row + 2][col] + Board[row + 2][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}
// ___|
inline void LSecond(int row, int col) {
  int num = Board[row + 1][col] + Board[row + 1][col + 1] +
            Board[row + 1][col + 2] + Board[row][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}
// |___
inline void LSecondMirror(int row, int col) {
  int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
            Board[row + 1][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}
// ---|
inline void LThird(int row, int col) {
  int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
            Board[row + 1][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}
// |---
inline void LThirdMirror(int row, int col) {
  int num = Board[row][col] + Board[row + 1][col] + Board[row][col + 1] +
            Board[row][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}
// |-
inline void LForth(int row, int col) {
  int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col] +
            Board[row + 2][col];
  if (maximum < num) {
    maximum = num;
  }
}

// -|
inline void LForthMirror(int row, int col) {
  int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col + 1] +
            Board[row + 2][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}

// |
// -
//  |
inline void SFirst(int row, int col) {
  int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
            Board[row + 2][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}

//   |
//  -
// |
inline void SFirstMirror(int row, int col) {
  int num = Board[row][col + 1] + Board[row + 1][col] +
            Board[row + 1][col + 1] + Board[row + 2][col];
  if (maximum < num) {
    maximum = num;
  }
}

// _|-
inline void SSecond(int row, int col) {
  int num = Board[row + 1][col] + Board[row + 1][col + 1] +
            Board[row][col + 1] + Board[row][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}

// -|_
inline void SSecondMirror(int row, int col) {
  int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col + 1] +
            Board[row + 1][col + 2];
  if (maximum < num) {
    maximum = num;
  }
}

// ㅜ
inline void HFirst(int row, int col) {
  int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
            Board[row + 1][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}

// ㅏ
inline void HSecond(int row, int col) {
  int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
            Board[row + 2][col];
  if (maximum < num) {
    maximum = num;
  }
}

// ㅗ
inline void HThird(int row, int col) {
  int num = Board[row][col + 1] + Board[row + 1][col + 1] +
            Board[row + 1][col + 2] + Board[row + 1][col];
  if (maximum < num) {
    maximum = num;
  }
}

// ㅓ
inline void HForth(int row, int col) {
  int num = Board[row][col + 1] + Board[row + 1][col] +
            Board[row + 1][col + 1] + Board[row + 2][col + 1];
  if (maximum < num) {
    maximum = num;
  }
}

void putTetromino(int i, int j) {
  IHorizon(i, j);
  IVertical(i, j);
  Square(i, j);
  if (j + 1 < w && i + 2 < h) {
    LFirst(i, j);
    LFirstMirror(i, j);
    LForth(i, j);
    LForthMirror(i, j);
    HForth(i, j);
    HSecond(i, j);
    SFirst(i, j);
    SFirstMirror(i, j);
  }
  if (j + 2 < w && i + 1 < h) {
    LSecond(i, j);
    LSecondMirror(i, j);
    LThird(i, j);
    LThirdMirror(i, j);
    HThird(i, j);
    HFirst(i, j);
    SSecond(i, j);
    SSecondMirror(i, j);
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> Board[i][j];
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      putTetromino(i, j);
    }
  }
  cout << maximum;
}
