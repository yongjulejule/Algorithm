#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// A B C D
// A + A*B + A(B+C) + A(B+C+D) + B + B*C + B(C+D) + B(C+D+A) + C + C*D + C(D+A)
// + C(D+A+B) + D + D*A + D(A+B) + D(A+B+C)
// A(1 + B + B + C + B + C + D)

// A 2 B 1
// A + B + A*B
// A(1 + B) + B
int getTotalCombination(const int &sum, map<string, int> &fashion) {
  auto it = fashion.begin(), ite = fashion.end();
  auto size = fashion.size();
  int ret[30];
  int i = 0;
  for (; it != ite; ++it) {
    cout << "key : " << it->first << " value : " << it->second
         << " size : " << size << '\n';
    auto cur = it;
    ++cur;
    int cnt = 0;
    ret[i] = 1;
    while (cur != ite) {
      ++cnt;
      cout << cur->first << ':' << cur->second << "," << cnt << '\n';
      ret[i] += (cur->second * (size - cnt));
      ++cur;
    }
    cout << "ret[" << i << "] : " << ret[i] << endl;
    ret[i] *= it->second;
    cout << "ret[" << i << "] : " << ret[i] << endl;
    ++i;
  }
  int total = 0;
  for (int i = 0; i < size; ++i) {
    cout << ret[i] << ", ";
    total += ret[i];
  }
  cout << endl;
  return total;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCase, nbr;
  cin >> testCase;

  string garment, kind;
  while (testCase--) {
    int sum = 0;
    cin >> nbr;
    map<string, int> fashion;
    while (nbr--) {
      cin >> garment >> kind;
      ++fashion[kind];
      ++sum;
    }
    cout << getTotalCombination(sum, fashion) << '\n';
  }
}

// a A
// b A
// c A
// d A
// e B
// f B
// g B
// h C
// i C
// j C
// k C
// l C

// A + B + C | A*B + B*C + A*C | (A+B)*C + (A+C) * B + (B+C) * A
// A + A*B + A(B+C) + B + B*C + B(A+C) + C + C*A + C(A+B)
