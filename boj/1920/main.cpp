#include <iostream>
#include <set>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  set<int> s;
  while (N--) {
    int A;
    cin >> A;
    s.insert(A);
  }
  int M;
  cin >> M;
  while (M--) {
    int nbr;
    cin >> nbr;
    cout << s.count(nbr) << "\n";
  }
  return 0;
}