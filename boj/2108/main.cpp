/*
산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
귀찮아.......
*/

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int idx[8001] = {
    0,
};

int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int *nbr = new int[N];
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> nbr[i];
    ++idx[nbr[i] + 4000];
    sum += nbr[i];
  }
  int max_idx = max_element(idx, idx + 8001) - idx;
  int sec_idx = find(idx + max_idx + 1, idx + 8001, idx[max_idx]) - idx;
  if (sec_idx > max_idx && sec_idx < 8001) max_idx = sec_idx;
  sort(nbr, nbr + N);
  cout << lround(static_cast<double>(sum) / N) << "\n"
       << nbr[N / 2] << "\n"
       << max_idx - 4000 << "\n"
       << nbr[N - 1] - nbr[0] << "\n";
  delete[] nbr;
}