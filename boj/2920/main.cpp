#include <iostream>
#include <string>

using namespace std;
int main() {
  string a("1 2 3 4 5 6 7 8");
  string d("8 7 6 5 4 3 2 1");
  string in;
  getline(cin, in);
  in == a   ? cout << "ascending"
  : in == d ? cout << "descending"
            : cout << "mixed";
}
