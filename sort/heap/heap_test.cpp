#include "Heap.hpp"
using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int a[10] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // for (int i = 0; i < 10; ++i) {
  //   test.push(a[i]);
  // }
  vector<int> a{1, 5, 2, 41, 234, 53};
  // vector<int> a{1, 5, 2};
  Heap<int, less<int> > test(a.begin(), a.end());
  for (auto& v : test) {
    cout << v << ", ";
  }
  cout << endl;
  auto ss = test.size();
  for (int i = 0; i <= ss; ++i) {
    cout << "i : " << i << '\n';
    cout << test.front();
    test.pop();
    cout << endl;
  }
  cout << endl;
  // Heap<char>(c, b);
}
