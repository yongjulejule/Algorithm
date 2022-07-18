#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
inline pair<string, string> channelEqualRange(int N, bool buttons[]) {
  const string s = to_string(N);
  const int len = s.size();
  string lowerBound(len, 0), upperBound(len, 0);
  for (int i = 0; i < 10; ++i) {
    int lowerIdx = s[0] - '0' - i;
    if (lowerIdx < 1) lowerIdx = 0;
    int upperIdx = s[0] - '0' + i;
    if (upperIdx > 9) upperIdx = 9;
    if (upperBound[0] && lowerBound[0]) break;
    if (!lowerBound[0] && buttons[lowerIdx]) {
      lowerBound[0] = lowerIdx + '0';
    }
    if (!upperBound[0] && buttons[upperIdx]) {
      upperBound[0] = upperIdx + '0';
    }
  }
  for (int j = 1; j < len; ++j) {
    for (int i = 0; i < 10; ++i) {
      int lowerIdx = s[j] - '0' + i;
      if (lowerIdx > 9) lowerIdx = 9;
      int upperIdx = s[j] - '0' - i;
      if (upperIdx < 0) upperIdx = 0;
      if (upperBound[j] && lowerBound[j]) break;
      if (!lowerBound[j] && buttons[lowerIdx]) {
        lowerBound[j] = lowerIdx + '0';
      }
      if (!upperBound[j] && buttons[upperIdx]) {
        upperBound[j] = upperIdx + '0';
      }
    }
  }
  auto ret = find_if(upperBound.begin(), upperBound.end(),
                     [](char &c) { return !isdigit(c); });
  if (ret != upperBound.end()) upperBound = "-1000000";
  ret = find_if(lowerBound.begin(), lowerBound.end(),
                [](char &c) { return !isdigit(c); });
  if (ret != lowerBound.end()) lowerBound = "-1000000";

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
  cout << ret.first << " " << ret.second << "\n";
  auto ans = abs(stoi(ret.first) - N) < abs(stoi(ret.second) - N) ? ret.first
                                                                  : ret.second;
  cout << (abs(N - stoi(ans)) + ans.size()) << "\n";
  return 0;
}