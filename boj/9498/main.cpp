#include <iostream>

using namespace std;
int main() {
  char a;
  int N;
  cin >> N;
  N >= 90   ? a = 'A'
  : N >= 80 ? a = 'B'
  : N >= 70 ? a = 'C'
  : N >= 60 ? a = 'D'
            : a = 'F';
  cout << a << "\n";
  return 0;
}