#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <vector>
#endif  // gcc or not
#define MOD 1000

template <typename T>
class Matrix {
 private:
  std::vector<std::vector<T> > matrix_;

 public:
  // constructor
  Matrix() {}
  Matrix(int32_t row, int32_t col, T val = T()) {
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
  int32_t rowSize() const { return matrix_.size(); }
  int32_t colSize() const { return matrix_[0].size(); }
  bool empty() const { return matrix_.empty(); }

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
  std::vector<T>& operator[](int32_t idx) { return matrix_[idx]; }
  const std::vector<T>& operator[](int32_t idx) const { return matrix_[idx]; }

  std::vector<T> getRowVec(int32_t idx) { return matrix_[idx]; }
  const std::vector<T> getRowVec(int32_t idx) const { return matrix_[idx]; }

  std::vector<T> getColVec(int32_t idx) {
    std::vector<T> tmp;
    tmp.reserve(this->colSize());
    for (int32_t i = 0; i < this->rowSize(); ++i) {
      tmp.push_back(matrix_[i][idx]);
    }
    return tmp;
  }
  const std::vector<T> getColVec(int32_t idx) const {
    std::vector<T> tmp;
    tmp.reserve(this->colSize());
    for (int32_t i = 0; i < this->colSize(); ++i) {
      tmp.push_back(matrix_[i][idx]);
    }
    return tmp;
  }

  // arithmetic operator
  T innerProduct(std::vector<T> v1, std::vector<T>&& v2) {
    T tmp = T();
    int32_t sz = v1.size();
    for (int32_t i = 0; i < sz; ++i) {
      tmp += v1[i] * v2[i];
    }
    return tmp;
  }

  Matrix<T> operator*(Matrix& rhs) {
    Matrix<T> tmp(this->rowSize(), rhs.colSize());
    for (int32_t i = 0; i < tmp.rowSize(); ++i) {
      for (int32_t j = 0; j < tmp.colSize(); ++j) {
        tmp[i][j] =
            innerProduct(this->getRowVec(i), std::move(rhs.getColVec(j)));
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
      typename std::enable_if<std::is_arithmetic<U>::value, U>::type rhs);
  template <typename U>
  friend Matrix<U> operator/(
      Matrix<U>& lhs,
      typename std::enable_if<std::is_arithmetic<U>::value, U>::type rhs);
  template <typename U>
  friend Matrix<U> operator%(
      Matrix<U>& lhs,
      typename std::enable_if<std::is_integral<U>::value, U>::type rhs);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);

  // ===========================================
  // FOR PS
  // ===========================================
  Matrix<T>& operator%=(int32_t mod) {
    for (int32_t i = 0; i < this->rowSize(); ++i) {
      for (int32_t j = 0; j < this->colSize(); ++j) {
        (*this)[i][j] %= mod;
      }
    }
    return *this;
  }
  Matrix<T> operator%(int32_t mod) {
    Matrix<T> tmp(*this);
    for (int32_t i = 0; i < this->rowSize(); ++i) {
      for (int32_t j = 0; j < this->colSize(); ++j) {
        tmp[i][j] %= mod;
      }
    }
    return tmp;
  }

 public:
  std::vector<std::vector<T> > colVec_;
  Matrix(const std::vector<std::vector<T> >& colVec) : matrix_(colVec) {}
  void genColVec() {
    colVec_.reserve(this->rowSize());
    for (int32_t i = 0; i < this->rowSize(); ++i) {
      colVec_.push_back(std::move(getColVec(i)));
    }
  }
};

template <typename U>
Matrix<U> operator*(Matrix<U>&& lhs, Matrix<U>&& rhs) {
  Matrix<U> tmp = lhs.operator*(rhs);
  return tmp;
}

template <typename U>
Matrix<U> operator*(
    Matrix<U>& lhs,
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type rhs) {
  auto colSize = lhs.colSize();
  auto rowSize = lhs.rowSize();
  Matrix<U> tmp(lhs);
  for (int32_t i = 0; i < rowSize; ++i) {
    for (int32_t j = 0; j < colSize; ++j) {
      tmp[i][j] *= rhs;
    }
  }
  return tmp;
}

template <typename U>
Matrix<U> operator/(
    Matrix<U>& lhs,
    typename std::enable_if<std::is_arithmetic<U>::value, U>::type rhs) {
  auto colSize = lhs.colSize();
  auto rowSize = lhs.rowSize();
  Matrix<U> tmp(lhs);
  for (int32_t i = 0; i < rowSize; ++i) {
    for (int32_t j = 0; j < colSize; ++j) {
      tmp[i][j] /= rhs;
    }
  }
  return tmp;
}
template <typename U>
Matrix<U> operator%(
    Matrix<U>& lhs,
    typename std::enable_if<std::is_integral<U>::value, U>::type rhs) {
  auto colSize = lhs.colSize();
  auto rowSize = lhs.rowSize();
  Matrix<U> tmp(lhs);
  for (int32_t i = 0; i < rowSize; ++i) {
    for (int32_t j = 0; j < colSize; ++j) {
      tmp[i][j] %= rhs;
    }
  }
  return tmp;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& m) {
  auto rowSize = m.rowSize();
  auto colSize = m.colSize();
  for (int32_t i = 0; i < rowSize; ++i) {
    for (int32_t j = 0; j < colSize; ++j) {
      os << m[i][j];
      os << " ";
    }
    os << '\n';
  }
  return os;
}

using namespace std;
unordered_map<int64_t, Matrix<int64_t> > memo;

Matrix<int64_t>& powMatrix(int64_t sq) {
  if (!memo[sq].empty()) return memo[sq];
  memo[sq] = sq & 1 ? ((powMatrix(sq >> 1) * (powMatrix(sq >> 1))) * memo[1])
                    : powMatrix(sq >> 1) * powMatrix(sq >> 1);
  memo[sq] %= MOD;
  return memo[sq];
}
