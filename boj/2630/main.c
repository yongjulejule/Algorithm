#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool paper[128][128];
int color[2] = {0, 0};
uint8_t Size = 0;

void divide(uint8_t s1, uint8_t s2, uint8_t e1, uint8_t e2) {
  bool c = paper[s1][s2];
  bool flag = true;
  for (int i = s1; i < e1 && flag; ++i) {
    for (int j = s2; j < e2 && flag; ++j) {
      if (c != paper[i][j]) {
        flag = false;
        divide(s1, s2, (s1 + e1) >> 1, (s2 + e2) >> 1);
        divide((s1 + e1) >> 1, s2, e1, (s2 + e2) >> 1);
        divide(s1, (s2 + e2) >> 1, (s1 + e1) >> 1, e2);
        divide((s1 + e1) >> 1, (s2 + e2) >> 1, e1, e2);
      }
    }
  }
  if (flag) ++color[c];
}

int main() {
  scanf("%d", &Size);
  for (int i = 0; i < Size; ++i) {
    for (int j = 0; j < Size; ++j) {
      scanf("%d", &paper[i][j]);
    }
  }
  divide(0, 0, Size, Size);
  printf("%d\n%d\n", color[0], color[1]);
}
