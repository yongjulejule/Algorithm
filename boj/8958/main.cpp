#include <iostream>
#include <string>

using namespace std;
int main() {
  int N;
  cin >> N;
  while (N--) {
    string s;
    cin >> s;
    int sum = 0;
    size_t len = s.length();

    int n = 0;
    for (size_t i = 0; i < len; i++) {
      s[i] == 'O' ? ++n : n = 0;
      sum += n;
    }
    cout << sum << "\n";
  }
}