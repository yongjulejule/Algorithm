#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (!(n % 400) || (!(n % 4) && (n % 100))) << "\n";
}