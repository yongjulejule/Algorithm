#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int k, num;
  cin >> k >> num;
  int sum = 0;
  vector<int> vLine;
  vLine.reserve(k);
  while (k--) {
    int cm;
    cin >> cm;
    vLine.push_back(cm);
    sum += cm;
  }

  long long ub = *max_element(vLine.begin(), vLine.end());
  long long lb = 1;
  long long cm2 = ub;
  while (true) {
    int nbr = 0;
    if (!cm2) cm2 = 1;
    for_each(vLine.begin(), vLine.end(), [&](int i) { nbr += (i / cm2); });
    if (nbr >= num) {
      lb = cm2;
    } else {
      ub = cm2;
    }
    if (((nbr >= num) && (ub - lb <= 1))) {
      break;
    }
    cm2 = (ub + lb) / 2;
  }
  cout << cm2 << "\n";
}

// 80 true -> lb = 0 ub = 80 => ret = 40
// 40 false -> lb = 40 ub = 80 => ret = 60
// 60 true -> lb = 40 ub = 60 => ret = 50
// 50 false -> lb = 50 ub = 60 => ret = 55
// 55 true -> lb = 55 ub = 60 => ret = 57
// 57 true -> end