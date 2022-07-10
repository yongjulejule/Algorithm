#include <algorithm>
#include <iostream>
#include <set>

int cards[101] = {
    0,
};

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  for_each(cards, cards + N, [](int &x) { cin >> x; });
  set<int> s;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N; ++k) {
        s.insert(cards[i] + cards[j] + cards[k]);
      }
    }
  }
  auto ans = s.lower_bound(M);
  if (ans == s.end()) --ans;
  cout << ((M < *ans) ? *(--ans) : *ans) << "\n";
}