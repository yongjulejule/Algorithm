#include <cmath>
#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std;
template <typename T>
static constexpr inline T pown(T x, unsigned p) {
  T result = 1;
  if (x == 2) return x << (p - 1);

  while (p) {
    if (p & 0x1) {
      result *= x;
    }
    x *= x;
    p >>= 1;
  }

  return result;
}

int main() {
  {
    unsigned long long val1;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 100; ++i) val1 = pown(3ULL, 10);
    auto end = chrono::steady_clock::now();
    cout << "my pown loop elapsed time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns"
         << "res : " << val1 << endl;
  }
  {
    unsigned long long val2;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 100; ++i) val2 = pow(3ULL, 10);
    auto end = chrono::steady_clock::now();
    cout << "lib pow loop elapsed time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns"
         << " res : " << val2 << endl;
  }
}
