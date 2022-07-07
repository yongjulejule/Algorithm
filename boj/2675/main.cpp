#include <iostream>
#include <string>

using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    int r = 0;
    string s;
    cin >> r >> s;
    for (char &c : s) {
      for (int i = 0; i < r; ++i) cout << c;
    }
    cout << "\n";
  }
}