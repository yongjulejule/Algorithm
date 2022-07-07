#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isShumNum(int n) {
  int ret = 0;
  while (n) {
    if (n % 1000 == 666) return true;
    n /= 10;
  }
  return ret > 2;
}

int main() {
  int N;
  cin >> N;
  vector<int> v;
  v.reserve(N);
  int num = 666;
  while (N--) {
    while (!isShumNum(num)) num++;
    v.push_back(num);
    ++num;
  }
  cout << *(--v.end()) << "\n";
}