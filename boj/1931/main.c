#include <stdio.h>

int compare(const void* a, const void* b) {}
int main() {
  int N;
  scanf("%d", N);
  int meeting[2][N];

  for (int i = 0; i < N; ++i) {
    scanf("%d%d", meeting[0][i], meeting[1][i]);
  }
  sort(meeting, meeting + N, [](auto& a, auto& b) {
    return (a.first < b.first)  ? true
           : a.first == b.first ? a.second < b.second
                                : false;
  });
  int cnt = 1;
  int cur = meeting[0].second;
  for (int i = 1; i < N; ++i) {
    if (meeting[i].first < cur && cur <= meeting[i].second) continue;
    if (cur <= meeting[i].first) ++cnt;
    cur = meeting[i].second;
  }
  printf("%d", cnt);
}