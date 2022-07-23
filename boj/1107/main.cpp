#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int M;
  int N;
  cin >> N >> M;
  bool buttons[10];
  memset(buttons, true, 10);
  for (int i = 0; i < M; ++i) {
    int nbr;
    cin >> nbr;
    buttons[nbr] = false;
  }
  int ans[4];
  for (int i = 0; i < 25000; ++i) {
  }
  return 0;
}