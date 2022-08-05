#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#endif  // gcc or not

using namespace std;

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  map<int, int> m;
  unordered_map<int, int> om;
  pair<int, int> *pr;
  vector<pair<int, int> > v;
  deque<pair<int, int> > dq;
  long long e1, e2, e3, e4, e5;
  {
    {
      auto start = chrono::steady_clock::now();
      /* Insert Your First Test Cases */

      for (int i = 0; i < 100000; ++i) {
        m.insert({i, i});
      }
      auto end = chrono::steady_clock::now();
      e1 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      cout << "Map elapsed time: \033[32m" << e1 << " ns\033[0m" << endl;
    }
    {
      auto start = chrono::steady_clock::now();
      /* Insert Your Second Test Cases */

      for (int i = 0; i < 100000; ++i) {
        om.insert({i, i});
      }
      auto end = chrono::steady_clock::now();
      e2 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      cout << "unordered_map elapsed time: \033[32m" << e2 << " ns\033[0m"
           << endl;
    }
    {
      auto start = chrono::steady_clock::now();
      /* Insert Your Second Test Cases */
      pr = new pair<int, int>[100000];

      for (int i = 0; i < 100000; ++i) {
        pr[i] = {i, i};
      }
      sort(pr, pr + 100000);
      delete[] pr;
      auto end = chrono::steady_clock::now();
      e3 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      cout << "Pair array elapsed time: \033[32m" << e3 << " ns\033[0m" << endl;
    }
    {
      auto start = chrono::steady_clock::now();
      /* Insert Your Second Test Cases */
      v.reserve(100000);

      for (int i = 0; i < 100000; ++i) {
        v.push_back({i, i});
      }
      sort(v.begin(), v.end());
      auto end = chrono::steady_clock::now();
      e4 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      cout << "Vector elapsed time: \033[32m" << e4 << " ns\033[0m" << endl;
    }
    {
      auto start = chrono::steady_clock::now();
      /* Insert Your Second Test Cases */

      for (int i = 0; i < 100000; ++i) {
        dq.push_back({i, i});
      }
      sort(dq.begin(), dq.end());
      auto end = chrono::steady_clock::now();
      e5 = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
      cout << "Deque elapsed time: \033[32m" << e5 << " ns\033[0m" << endl;
    }
    cout << "Vector를 1로 뒀을때 걸린 시간\n(Map, unordered_map, pair[], "
            "vector, deque)\n\033[32m"
         << double(e1) / double(e4) << ", " << double(e2) / double(e4) << ", "
         << double(e3) / double(e4) << ", " << double(e4) / double(e4) << ", "
         << double(e5) / double(e4) << "\033[0m" << endl;
    cerr << double(e1) / double(e4) << ", " << double(e2) / double(e4) << ", "
         << double(e3) / double(e4) << ", " << double(e4) / double(e4) << ", "
         << double(e5) / double(e4) << endl;
  }
}