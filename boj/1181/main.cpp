#include <iostream>
#include <set>
#include <vector>

struct comp {
  bool operator()(const std::string &a, const std::string &b) const {
    return (a.size() < b.size()) ||
           (a.size() == b.size() &&
            lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()));
  }
};

int main() {
  int N;
  std::cin >> N;
  std::set<std::string, comp> sSet;
  for (int i = 0; i < N; ++i) {
    std::string s;
    std::cin >> s;
    sSet.insert(s);
  }
  for (auto &s : sSet) {
    std::cout << s << "\n";
  }
}