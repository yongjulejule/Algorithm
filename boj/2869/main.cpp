#include <iostream>

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int A, B, V;
  cin >> A >> B >> V;
  if (A == V) {
    cout << 1 << endl;
    return 0;
  }
  int ba = A - B, va = V - B - 1;
  int days = va / ba;
  if (!days) days = 1;

  cout << days + 1 << "\n";
  return 0;
}