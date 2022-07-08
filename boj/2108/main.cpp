/*
산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
귀찮아.......
*/

#include <iostream>
#include <map>
#include <set>

using namespace std;
int main() {
  int idx[500001] = {
      0,
  };
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  cout << N;
  int *nbr = new int[N];
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> nbr[i];
    ++idx[nbr[i]];
    sum += nbr[i];
  }
  multimap<int, int> m;
  for (int i = 0; i < N; ++i) {
    m.insert(make_pair(idx[nbr[i]], nbr[i]));
  }
  int max = 0;
  auto range = m.equal_range(m.rbegin()->first);
  if (range.second == m.end())
    max = range.first->second;
  else {
    set<int> ss;
    for_each(range.first, range.second,
             [&ss](auto &p) { ss.insert(p.second); });
    max = *(++ss.begin());
  }
  sort(nbr, nbr + N);
  cout << "================\n";
  cout << sum / N << "\n"
       << nbr[N / 2] << "\n"
       << max << "\n"
       << nbr[N - 1] - nbr[0] << "\n";
  delete[] nbr;
}