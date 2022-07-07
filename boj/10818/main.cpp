#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    v[i] = n;
  }
  set<int> s(v.begin(), v.end());
  cout << *(s.begin()) << " " << *(--s.end()) << "\n";
}