#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
inline pair<string, string> channelEqualRange(int N, bool buttons[]) {
  const string s = to_string(N);
  const int len = s.size();
  int min = 0, max = 9;
  while (!buttons[min] && min < 9) ++min;
  while (!buttons[max] && max > 0) --max;
  string lowerBound(len, 0), upperBound(len, 0);
  for (int i = 0; i < 10; ++i) {
    int lowerIdx = s[0] - '0' - i;
    if (lowerIdx <= min) lowerIdx = min;
    int upperIdx = s[0] - '0' + i;
    if (upperIdx >= max) upperIdx = max;
    if (upperBound[0] && lowerBound[0]) break;
    if (!lowerBound[0] && buttons[lowerIdx]) {
      lowerBound[0] = lowerIdx + '0';
    }
    if (!upperBound[0] && buttons[upperIdx]) {
      upperBound[0] = upperIdx + '0';
    }
  }
  cout << lowerBound << ", " << upperBound << '\n';
  for (int j = 1; j < len; ++j) {
    for (int i = 0; i < 10; ++i) {
      int lowerIdx = s[j] - '0' + 9 - i;
      if (lowerIdx >= max) lowerIdx = max;
      int upperIdx = s[j] - '0' - i;
      if (upperIdx <= min) upperIdx = min;
      if (upperBound[j] && lowerBound[j]) break;
      if (!lowerBound[j] && buttons[lowerIdx]) {
        lowerBound[j] = lowerIdx + '0';
      }
      if (!upperBound[j] && buttons[upperIdx]) {
        upperBound[j] = upperIdx + '0';
      }
    }
  }
  return {lowerBound, upperBound};
}

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
  if (97 < N && N < 104) {
    cout << abs(N - 100) << "\n";
    return 0;
  }
  auto ret = channelEqualRange(N, buttons);
  auto ans = abs(stoi(ret.first) - N) < abs(stoi(ret.second) - N) ? ret.first
                                                                  : ret.second;
  cout << (abs(N - stoi(ans)) + ans.size()) << "\n";
  return 0;
}