#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <unordered_map>
#endif  // gcc or not

#define MOD 1000000007ULL

using namespace std;
unordered_map<uint64_t, uint64_t> memo;

inline uint64_t square(uint64_t num) { return num * num; }

uint64_t fib(uint64_t num) {
  if (memo[num] != 0) {
    return memo[num];
  } else {
    auto ret = (num & 1)
                   ? (square(fib((num >> 1) + 1ULL) % MOD) % MOD) +
                         (square(fib((num >> 1)) % MOD) % MOD)
                   : ((fib((num >> 1) - 1) % MOD) * (fib(num >> 1) % MOD)) +
                         (fib(num >> 1) % MOD) * (fib((num >> 1) + 1) % MOD);
    ret %= MOD;
    memo[num] = ret;
    return ret;
  }
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  uint64_t N;
  cin >> N;
  memo[0] = 0, memo[1] = 1, memo[2] = 1, memo[3] = 2, memo[4] = 3, memo[5] = 5;
  cout << fib(N) << '\n';
  return 0;
}

// F_2n-1 = F_(n) ^2 + F_(n-1) ^2
// F_2n = F_(n - 1) * F_n + F_(n) * F_(n + 1)