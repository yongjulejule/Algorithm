#include <iostream>

using namespace std;
int main() {
  while (true) {
    int a, b;
    cin >> a;
    if (!cin.good() || cin.eof()) break;
    cin >> b;
    if (!cin.good() || cin.eof()) break;
    cout << a + b << "\n";
  }
}