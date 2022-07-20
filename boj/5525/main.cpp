#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned int N, len;
  string given;
  cin >> N >> len >> given;
  auto givenIt = given.begin(), givenIte = given.end();
  auto size = 2 * N + 1;
  string my(size, 'I');
  for (unsigned int i = 1; i < size; i += 2) {
    my[i] = 'O';
  }
  auto myIt = my.begin(), myIte = my.end();
  int cnt = 0;
  while (true) {
    givenIt = search(givenIt, givenIte, myIt, myIte);
    if (givenIt == givenIte) break;
    givenIt += 2;
    ++cnt;
  }
  cout << cnt << '\n';
}