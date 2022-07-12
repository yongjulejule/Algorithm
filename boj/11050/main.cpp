#include <iostream>

using namespace std;

template <int N>
struct Factorial {
  static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1> {
  static const int result = 1;
};

typedef Factorial<10> ten;
typedef Factorial<9> nine;
typedef Factorial<8> eight;
typedef Factorial<7> seven;
typedef Factorial<6> six;
typedef Factorial<5> five;
typedef Factorial<4> four;
typedef Factorial<3> three;
typedef Factorial<2> two;
typedef Factorial<1> one;

template <typename T>
inline int getValue(T) {
  return T::result;
}

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int values[11] = {1,
                    one::result,
                    two::result,
                    three::result,
                    four::result,
                    five::result,
                    six::result,
                    seven::result,
                    eight::result,
                    nine::result,
                    ten::result};
  int n, k;
  cin >> n >> k;
  cout << values[n] / (values[k] * values[n - k]) << '\n';
  return 0;
}