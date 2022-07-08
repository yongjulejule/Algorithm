#include <iostream>

using namespace std;

inline bool isPrime(int &nbr) {
  if (nbr == 1) return false;
  for (int i = 2; i * i <= nbr; i++) {
    if (nbr % i == 0) return false;
  }
  return true;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int cnt = 0;
  while (N--) {
    int nbr;
    cin >> nbr;
    cnt += isPrime(nbr);
  }
  cout << cnt << "\n";
}