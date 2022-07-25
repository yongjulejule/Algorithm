#include <cstdint>
#include <iostream>

using namespace std;
int sum[100001];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int numbers, testCase;
  cin >> numbers >> testCase;
  int n;
  for (int i = 1; i <= numbers; ++i) {
    cin >> n;
    sum[i] = sum[i - 1] + n;
  }
  int i, j;
  while (testCase--) {
    cin >> i >> j;
    cout << sum[j] - sum[i - 1] << '\n';
  }
}