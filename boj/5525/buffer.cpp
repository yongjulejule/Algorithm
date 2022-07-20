#include <cstdio>
#include <cstring>

char buf[1000001];
char my[2000002];

int main() {
  unsigned int N, len;
  scanf("%d%d%s", &N, &len, buf);
  int cnt = 0;
  for (int i = 0; i < len; ++i) {
    int ioi = 0;
    if (buf[i] == 'O')
      continue;
    else {
      while (buf[i + 1] == 'O' && buf[i + 2] == 'I') {
        ++ioi;
        if (ioi == N) {
          --ioi;
          ++cnt;
        }
        i += 2;
      }
      ioi = 0;
    }
  }

  printf("%d", cnt);
}
