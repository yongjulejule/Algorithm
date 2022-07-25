#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#define PLUS -1
#define MINUS -2
#define END -3

using namespace std;
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  getline(cin, s);
  auto pos = s.begin();
  auto end = s.end();
  int arr[60], ans[60], idx = 0, lastMinus = 0;
  memset(arr, END, sizeof(arr));
  memset(ans, 0, sizeof(ans));
  while (true) {
    auto b = pos;
    pos = find_if(pos, end, [](char &c) { return c == '+' || c == '-'; });
    arr[idx++] = stoi(string(b, pos));
    if (pos == end) {
      arr[idx] = END;
      break;
    }
    arr[idx++] = *pos == '+' ? PLUS : MINUS;
    if (*pos == '-') lastMinus = idx;
    ++pos;
  }

#ifndef BOJ
  {
    cout << "lastMinus : " << lastMinus << '\n';
    for (int i = 0; arr[i] != END; ++i) {
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
#endif

  ans[0] = arr[0];
  idx = 0;
  int i = 0;
  while (true) {
#ifndef BOJ
    cout << "i : " << i << " idx : " << idx << " arr[i] : " << arr[i]
         << " ans[idx] : " << ans[idx] << '\n';
#endif
    if (arr[i] == PLUS) {
      ans[idx] += arr[i + 1];
    } else if (arr[i] == MINUS) {
      ++idx;
      ans[idx] = arr[i + 1];
    } else if (arr[i] == END) {
      ans[idx + 1] = END;
      break;
    }
    ++i;
  }
#ifndef BOJ
  for (int i = 0; ans[i] != END; ++i) {
    cout << ans[i] << ", ";
  }
  cout << endl;
#endif
  int ret = ans[0];
  for (int i = 1; ans[i] != END; ++i) {
    ret -= ans[i];
  }
  cout << ret;
}
