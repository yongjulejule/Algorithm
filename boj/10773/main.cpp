#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<int> v;
  v.reserve(N);
  while (N--) {
    int k;
    cin >> k;
    if (!k)
      v.pop_back();
    else
      v.push_back(k);
  }
  long long sum = 0;
  for_each(v.begin(), v.end(), [&sum](int x) { sum += x; });
  cout << sum << '\n';
  return 0;
}