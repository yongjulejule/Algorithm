#include <iostream>

using namespace std;

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  if (N < 3 || N == 4 || N == 7) {
    cout << -1 << "\n";
    return 0;
  }

  if (N % 5 == 0) {
    cout << N / 5 << "\n";
  } else if (N % 5 == 1) {
    cout << N / 5 + 1 << "\n";
  } else if (N % 5 == 2) {
    cout << N / 5 + 2 << "\n";
  } else if (N % 5 == 3) {
    cout << N / 5 + 1 << "\n";
  } else {
    cout << N / 5 + 2 << "\n";
  }
}