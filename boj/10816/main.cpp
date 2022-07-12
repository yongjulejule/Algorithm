#include <iostream>
#include <set>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  multiset<int> mset;
  cin >> N;
  int *cards = new int[20000000];
  int index;
  for (int i = 0; i < N; ++i) {
    cin >> index;
    ++cards[index + 10000000];
  }
  cin >> M;
  int given;
  for (int i = 0; i < M; ++i) {
    cin >> given;
    cout << cards[given + 10000000] << " ";
  }

  cout << "\n";
  delete[] cards;
  return 0;
}