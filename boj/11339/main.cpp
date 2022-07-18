#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int *A = new int[N];
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum = sum + A[i];
    for (int j = 0; j < i; ++j) sum = sum + A[j];
  }
  cout << sum;
}