#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int points[1000000];
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> comp;
  comp.reserve(N);
  for (int i = 0; i < N; ++i) {
    cin >> points[i];
    comp.push_back(points[i]);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  auto it = comp.begin();
  auto ite = comp.end();

  for (int i = 0; i < N; ++i) {
    cout << lower_bound(it, ite, points[i]) - it << " ";
  }
}