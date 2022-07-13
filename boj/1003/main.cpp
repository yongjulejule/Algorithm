#include <iostream>
#include <map>

using namespace std;
map<int64_t, int64_t[3]> m;
int64_t origin;
int64_t fib(int64_t N) {
  if (m.find(N) != m.end()) {
    m[origin][1] += m[N][1];
    m[origin][2] += m[N][2];
    return m[N][0];
  }

  if (N == 0) {
    ++m[origin][1];
    return 0;
  }
  if (N == 1) {
    ++m[origin][2];
    return 1;
  }
  return fib(N - 1) + fib(N - 2);
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t T;
  cin >> T;
  for (int i = 0; i <= 50; ++i) {
    origin = i;
    m[i][0] = fib(i);
  }
  while (T--) {
    int64_t N, zero, one;
    cin >> N;
    zero = m[N][1];
    one = m[N][2];
    cout << zero << " " << one << "\n";
  }
}