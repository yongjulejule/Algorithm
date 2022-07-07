#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> v(0);
  int N, X;
  cin >> N >> X;
  for (int i = 0; i < N; ++i) {
    int ret;
    cin >> ret;
    if (ret < X) cout << ret << " ";
  }
  cout << "\n";
}