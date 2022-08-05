#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#endif  // gcc or not

template <typename T>
class Matrix {
 private:
  std::vector<std::vector<T> > matrix_;

 public:
  // constructor
  Matrix() {}
  Matrix(uint32_t row, uint32_t col, T val = T()) {
    matrix_.assign(row, std::vector<T>(col, val));
  }
  Matrix(const Matrix& src) : matrix_(src.matrix_) {}
  Matrix(Matrix&& src) : matrix_(std::move(src.matrix_)) {}

  // assign operator overload
  Matrix& operator=(const Matrix& src) {
    this->matrix_ = src.matrix_;
    return *this;
  }
  Matrix& operator=(Matrix&& src) {
    this->matrix_ = std::move(src.matrix_);
    return *this;
  }

  // destructor
  ~Matrix() { matrix_.clear(); }

  // capacity
  uint32_t rowSize() const { return matrix_.size(); }
  uint32_t colSize() const { return matrix_[0].size(); }

  // iterator
  typename std::vector<std::vector<T> >::iterator begin() {
    return matrix_.begin();
  }
  typename std::vector<std::vector<T> >::const_iterator begin() const {
    return matrix_.begin();
  }
  typename std::vector<std::vector<T> >::iterator end() {
    return matrix_.end();
  }
  typename std::vector<std::vector<T> >::const_iterator end() const {
    return matrix_.end();
  }

  // element access
  std::vector<T>& operator[](uint32_t idx) { return matrix_[idx]; }
  const std::vector<T>& operator[](uint32_t idx) const { return matrix_[idx]; }

  std::vector<T> getRowVec(uint32_t idx) { return matrix_[idx]; }
  const std::vector<T> getRowVec(uint32_t idx) const { return matrix_[idx]; }

  std::vector<T> getColVec(uint32_t idx) {
    std::vector<T> tmp;
    tmp.reserve(this->colSize());
    for (uint32_t i = 0; i < this->rowSize(); ++i) {
      tmp.push_back(matrix_[i][idx]);
    }
    return tmp;
  }
  const std::vector<T> getColVec(uint32_t idx) const {
    std::vector<T> tmp;
    tmp.reserve(this->colSize());
    for (uint32_t i = 0; i < this->colSize(); ++i) {
      tmp.push_back(matrix_[i][idx]);
    }
    return tmp;
  }

  // arithmetic operator
  T innerProduct(std::vector<T> v1, std::vector<T> v2) {
    T tmp = T();
    for (uint32_t i = 0; i < v1.size(); ++i) {
      tmp += v1[i] * v2[i];
    }
    return tmp;
  }

  Matrix<T> operator*(Matrix& rhs) {
    Matrix<T> tmp(this->rowSize(), rhs.colSize());
    for (uint32_t i = 0; i < tmp.rowSize(); ++i) {
      for (uint32_t j = 0; j < tmp.colSize(); ++j) {
        tmp[i][j] = innerProduct(this->getRowVec(i), rhs.getColVec(j));
      }
    }
    return tmp;
  }

  // non-member overload
  template <typename U>
  friend Matrix<U> operator*(Matrix<U>& lhs, Matrix<U>& rhs);
  template <typename U>
  friend Matrix<U> operator*(
      Matrix<U>& lhs,
      typename std::enable_if<std::is_arithmetic<T>::value, T>::type rhs);
  template <typename U>
  friend Matrix<U> operator/(
      Matrix<U>& lhs,
      typename std::enable_if<std::is_arithmetic<T>::value, T>::type rhs);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);
};

template <typename U>
Matrix<U> operator*(Matrix<U>& lhs, Matrix<U>& rhs) {
  Matrix<U> tmp = lhs.operator*(rhs);
  return tmp;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& m) {
  auto rowSize = m.rowSize();
  auto colSize = m.colSize();
  for (uint32_t i = 0; i < rowSize; ++i) {
    for (uint32_t j = 0; j < colSize; ++j) {
      os << m[i][j];
      if (j != colSize - 1) os << " ";
    }
    os << '\n';
  }
  return os;
}

using namespace std;
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int r1, c1, r2, c2;
  cin >> r1 >> c1;
  Matrix<int> a(r1, c1);
  for (int i = 0; i < r1; ++i) {
    for (int j = 0; j < c1; ++j) {
      cin >> a[i][j];
    }
  }
  cin >> r2 >> c2;
  Matrix<int> b(r2, c2);
  for (int i = 0; i < r2; ++i) {
    for (int j = 0; j < c2; ++j) {
      cin >> b[i][j];
    }
  }
  cout << (a * b);
  return 0;
}