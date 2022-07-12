#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  pair<int, int> *p = new pair<int, int>[N];
  for_each(p, p + N, [](pair<int, int> &pe) { cin >> pe.first >> pe.second; });
  sort(p, p + N, [](pair<int, int> &a, pair<int, int> &b) {
    return (a.first < b.first) || (a.first == b.first && a.second < b.second);
  });
  for_each(p, p + N, [](pair<int, int> &pe) {
    cout << pe.first << " " << pe.second << "\n";
  });
  return 0;
}