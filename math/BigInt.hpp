#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>

class BigInt {
 private:
  std::string _data;

 public:
  BigInt() : _data("") {}
  BigInt(std::string s) : _data(s) {}

  template <typename Integer>
  BigInt(Integer val, typename std::enable_if<std::is_integral<Integer>::value,
                                              Integer>::type * = nullptr)
      : _data(std::to_string(val)) {}
  BigInt(const BigInt &src) : _data(src._data) {}
  BigInt(BigInt &&src) : _data(src._data) { src._data = ""; }
  BigInt &operator=(const BigInt &src) {
    _data = src._data;
    return *this;
  }
  size_t size() const { return _data.size(); }
  bool empty() const { return _data == ""; }
  bool operator==(const BigInt &v) { return _data == v._data; }
  bool operator!=(const BigInt &v) { return _data != v._data; }

  friend BigInt operator+(BigInt rhs, BigInt lhs);

  ~BigInt() {}
  friend std::ostream &operator<<(std::ostream &os, const BigInt &src);
};

BigInt operator+(BigInt rhs, BigInt lhs) {
  int diff = static_cast<int>(rhs.size()) - static_cast<int>(lhs.size());
  if (diff > 0) {
    lhs._data = std::string(diff, '0') + lhs._data;
  } else if (diff < 0) {
    rhs._data = std::string(-1 * diff, '0') + rhs._data;
  }
  BigInt tmp;
  bool carry = false;
  for (int i = (rhs.size() - 1); i >= 0; --i) {
    int digit = rhs._data[i] - '0' + lhs._data[i] - '0' + carry;
    carry = false;
    if (digit > 9) {
      carry = true;
      digit %= 10;
    }
    tmp._data.push_back(digit + '0');
  }
  if (carry) tmp._data.push_back('1');
  std::reverse(tmp._data.begin(), tmp._data.end());
  return tmp;
}

std::ostream &operator<<(std::ostream &os, const BigInt &src) {
  os << src._data;
  return os;
}