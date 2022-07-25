#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int ret[19];
int maximum = 0;
int Board[500][500];
int w, h;

// ----
inline void IHorizon(int row, int col) {
  if (col + 3 < w) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
              Board[row][col + 3];
    if (ret[0] < num) {
      ret[0] = num;
    }
  }
}

// |
inline void IVertical(int row, int col) {
  if (row + 3 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 2][col] +
              Board[row + 3][col];
    if (ret[1] < num) {
      ret[1] = num;
    }
  }
}

// ㅁ
inline void Square(int row, int col) {
  if (col + 1 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row][col + 1] +
              Board[row + 1][col + 1];
    if (ret[2] < num) {
      ret[2] = num;
    }
  }
}
// L
inline void LFirst(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 2][col] +
              Board[row + 2][col + 1];
    if (ret[3] < num) {
      ret[3] = num;
    }
  }
}
// _|
inline void LFirstMirror(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col + 1] + Board[row + 1][col + 1] +
              Board[row + 2][col] + Board[row + 2][col + 1];
    if (ret[4] < num) {
      ret[4] = num;
    }
  }
}
// ___|
inline void LSecond(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row + 1][col] + Board[row + 1][col + 1] +
              Board[row + 1][col + 2] + Board[row][col + 2];
    if (ret[5] < num) {
      ret[5] = num;
    }
  }
}
// |___
inline void LSecondMirror(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
              Board[row + 1][col + 2];
    if (ret[6] < num) {
      ret[6] = num;
    }
  }
}
// ---|
inline void LThird(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
              Board[row + 1][col + 2];
    if (ret[7] < num) {
      ret[7] = num;
    }
  }
}
// |---
inline void LThirdMirror(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row][col + 1] +
              Board[row][col + 2];
    if (ret[8] < num) {
      ret[8] = num;
    }
  }
}
// |-
inline void LForth(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col] +
              Board[row + 2][col];
    if (ret[9] < num) {
      ret[9] = num;
    }
  }
}

// -|
inline void LForthMirror(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col + 1] +
              Board[row + 2][col + 1];
    if (ret[10] < num) {
      ret[10] = num;
    }
  }
}

// |
// -
//  |
inline void SFirst(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
              Board[row + 2][col + 1];
    if (ret[11] < num) {
      ret[11] = num;
    }
  }
}

//   |
//  -
// |
inline void SFirstMirror(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col + 1] + Board[row + 1][col] +
              Board[row + 1][col + 1] + Board[row + 2][col];
    if (ret[12] < num) {
      ret[12] = num;
    }
  }
}

// _|-
inline void SSecond(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row + 1][col] + Board[row + 1][col + 1] +
              Board[row][col + 1] + Board[row][col + 2];
    if (ret[13] < num) {
      ret[13] = num;
    }
  }
}

// -|_
inline void SSecondMirror(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row + 1][col + 1] +
              Board[row + 1][col + 2];
    if (ret[14] < num) {
      ret[14] = num;
    }
  }
}

// ㅜ
inline void HFirst(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col] + Board[row][col + 1] + Board[row][col + 2] +
              Board[row + 1][col + 1];
    if (ret[15] < num) {
      ret[15] = num;
    }
  }
}

// ㅏ
inline void HSecond(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col] + Board[row + 1][col] + Board[row + 1][col + 1] +
              Board[row + 2][col];
    if (ret[16] < num) {
      ret[16] = num;
    }
  }
}

// ㅗ
inline void HThird(int row, int col) {
  if (col + 2 < w && row + 1 < h) {
    int num = Board[row][col + 1] + Board[row + 1][col + 1] +
              Board[row + 1][col + 2] + Board[row + 1][col];
    if (ret[17] < num) {
      ret[17] = num;
    }
  }
}

// ㅓ
inline void HForth(int row, int col) {
  if (col + 1 < w && row + 2 < h) {
    int num = Board[row][col + 1] + Board[row + 1][col] +
              Board[row + 1][col + 1] + Board[row + 2][col + 1];
    if (ret[18] < num) {
      ret[18] = num;
    }
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
  maximum = *max_element(ret, ret + 19);
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  memset(ret, 0, sizeof(ret));
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
