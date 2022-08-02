#include <cstring>
#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#endif  // gcc or not

#define NIL -1

class BST {
 private:
  int* __tree;
  int __size;

  int leftChildIdx(int cur) {
    return (__tree[(cur << 1)] != NIL) ? cur << 1 : 0;
  }
  int rightChildIdx(int cur) {
    return (__tree[(cur << 1) + 1] != NIL) ? (cur << 1) + 1 : 0;
  }
  int& root() { return __tree[1]; }
  int& leftChild(int cur) { return __tree[leftChildIdx(cur)]; }
  int& rightChild(int cur) { return __tree[rightChildIdx(cur)]; }

 public:
  BST() : __size(0) {
    // __tree = std::allocator<int>().allocate(1 << 16);
    // memset(__tree, 0xff, (1 << 18));
  }
  bool empty() { return __size == 0; }
  void insert(int val) {
    if (empty()) {
      root() = val;
      ++__size;
      return;
    }
    int tmp = 1;
    while (__tree[tmp] != NIL) {
      if (__tree[tmp] > val)
        tmp <<= 1;
      else
        tmp = (tmp << 1) + 1;
    }
    __tree[tmp] = val;
    ++__size;
  }
  void preOrder(int cur) {
    if (__tree[cur] == NIL) return;
    std::cout << __tree[cur] << '\n';
    preOrder(leftChildIdx(cur));
    preOrder(rightChildIdx(cur));
  }
  void postOrder(int cur) {
    if (__tree[cur] == NIL) return;
    postOrder(leftChildIdx(cur));
    postOrder(rightChildIdx(cur));
    std::cout << __tree[cur] << '\n';
  }
  void inOrder(int cur) {
    if (__tree[cur] == NIL) return;
    inOrder(leftChildIdx(cur));
    std::cout << __tree[cur] << '\n';
    inOrder(rightChildIdx(cur));
  }
  ~BST() { delete __tree; }
};

using namespace std;
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  BST t;
  while (cin.good()) {
    int i;
    cin >> i;
    t.insert(i);
  }
  t.postOrder(1);
}