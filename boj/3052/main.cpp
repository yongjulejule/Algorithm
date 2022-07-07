#include <iostream>
#include <set>

using namespace std;
int main() {
  int a[10];
  set<int> s;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
    a[i] %= 42;
  }
  s.insert(a, a + 10);
  cout << s.size() << "\n";
}