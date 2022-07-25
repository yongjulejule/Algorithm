#include <stdio.h>
#include <unistd.h>

#include <iostream>

using namespace std;
int main() {
  // cout.tie(nullptr)->ios::sync_with_stdio(false);
  // cin.tie(nullptr)->ios::sync_with_stdio(false);
  // cerr.tie(nullptr)->ios::sync_with_stdio(false);
  char s[] = "HelloWorld\n";
  // for (int i = 0; i < 100; ++i) write(1, s, sizeof(s));
  // for (int i = 0; i < 100; ++i) printf("%s", s);
  // for (int i = 0; i < 100; ++i) cout << s;
  for (int i = 0; i < 100; ++i) puts(s);

  // {
  //   auto start = chrono::steady_clock::now();
  //   /* Insert Your First Test Cases */
  //   for (int i = 0; i < 100; ++i) {
  //     printf("%s", s);
  //   }

  //   auto end = chrono::steady_clock::now();
  //   cerr << "Test Case #1 elapsed time: "
  //        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
  //        << " ns" << endl;
  // }
  // {
  //   auto start = chrono::steady_clock::now();
  //   /* Insert Your Second Test Cases */
  //   for (int i = 0; i < 100; ++i) {
  //     cout << s;
  //   }

  //   auto end = chrono::steady_clock::now();
  //   cerr << "Test Case #2 elapsed time: "
  //        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
  //        << " ns" << endl;
  // }
  // {
  //   auto start = chrono::steady_clock::now();
  //   /* Insert Your Second Test Cases */
  //   for (int i = 0; i < 100; ++i) {
  //     write(1, s, sizeof(s));
  //   }

  //   auto end = chrono::steady_clock::now();
  //   cerr << "Test Case #2 elapsed time: "
  //        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
  //        << " ns" << endl;
  // }
}