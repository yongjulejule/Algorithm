#include <iostream>

using namespace std;
#define mod 10007
int DP[1001];
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  uint64_t N;
  cin >> N;
  DP[1] = 1;
  DP[2] = 2;  // DP[1] + 1
  for (uint64_t i = 3; i <= N; ++i) {
    DP[i] = ((DP[i - 1] % mod) + (DP[i - 2] % mod)) % mod;
  }
  cout << DP[N];
}

// |

// || ..

// ||| |.. ..|

// ||||
// ||.. |..| ..||
// ....

// |||||
// |||.. ||..| |..|| ..|||
// |.... ..|.. ....|

// ||||||
// ||||.. |||..| ||..|| |..||| ..||||
// ||.... |..|.. |....| ..||.. ..|..| ....||
// ......