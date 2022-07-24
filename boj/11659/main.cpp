#include <cstdint>
#include <iostream>

using namespace std;
int arr[100001];
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int numbers, testCase;
  cin >> numbers >> testCase;
  for (int i = 1; i <= numbers; ++i) {
    cin >> arr[i];
  }
  while (testCase--) {
    int i, j;
    uint64_t sum = 0;
    cin >> i >> j;
    for (; i <= j; ++i) {
      sum += arr[i];
    }
    cout << sum << '\n';
  }
}