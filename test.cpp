
#include <cmath>
#include <iostream>
#include <typeinfo>

#include "fixmath.h"

using namespace std;

template <typename T>
void print_bits(T x) {
  unsigned char *ch;
  cout.precision(10);
  cout << "type T is " << typeid(x).name() << ", value : " << x << endl;
  ch = reinterpret_cast<unsigned char *>(&x);
  cout << "print x as bits : " << bitset<8>(ch[3]) << ", " << bitset<8>(ch[2])
       << ", " << bitset<8>(ch[1]) << ", " << bitset<8>(ch[0]) << endl;
}

int main() {
  print_bits(42.0f);
  print_bits(42);
  print_bits(10);
  print_bits(numeric_limits<int>::max());
  print_bits(numeric_limits<int>::min());
  print_bits(numeric_limits<float>::max());
  print_bits(INFINITY);
  print_bits(-INFINITY);
  print_bits(NAN);

  Fix16 f(42.42f);
  cout << "fixed test : " << short(f) << "\n";
  int a = int{24};
  cout << a << "\n";
  return 0;
}