#if __GNUC__ && !__clang__
#include <bits/stdc++.h>
#else  // __clang__
#include <algorithm>
#include <iostream>
#endif  // gcc or not

using namespace std;
#include <algorithm>
#include <iostream>
#include <memory>

template <typename T>
struct Node {
  T data;
  Node* left;
  Node* right;
  Node() : data(T()), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
  using Node_t = Node<T>;
  using NodePtr_t = Node<T>*;
  using _Alloc = std::allocator<Node_t>;
  using alloc = std::allocator_traits<_Alloc>;

 private:
  NodePtr_t __root;
  _Alloc __a;

 public:
  BST() : __root(nullptr) {}
  BST(T val) : __root(newNode(val)) {}

  NodePtr_t const getRoot() { return __root; }

  NodePtr_t newNode(T& val = T()) {
    if (val == '.') return nullptr;
    NodePtr_t node = alloc::allocate(__a, 1);
    alloc::construct(__a, node, Node_t());
    node->data = val;
    return node;
  }

  void find(NodePtr_t cur, NodePtr_t& f, T val) {
    if (cur == nullptr) return;
    if (cur->data == val) f = cur;
    find(cur->left, f, val);
    find(cur->right, f, val);
  }

  void insert(T val, T left, T right) {
    NodePtr_t tmp;
    find(__root, tmp, val);
    tmp->left = newNode(left);
    tmp->right = newNode(right);
  }
  void deleteTree(NodePtr_t cur) {
    if (cur == nullptr) return;
    deleteTree(cur->left);
    deleteTree(cur->right);
    alloc::destroy(__a, cur);
    alloc::deallocate(__a, cur, 1);
  }
  void preOrder() { preOrder(__root); }
  void postOrder() { postOrder(__root); }
  void inOrder() { inOrder(__root); }
  void preOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    std::cout << cur->data;
    preOrder(cur->left);
    preOrder(cur->right);
  }
  void postOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    postOrder(cur->left);
    postOrder(cur->right);
    std::cout << cur->data;
  }
  void inOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    inOrder(cur->left);
    std::cout << cur->data;
    inOrder(cur->right);
  }
  ~BST() { deleteTree(__root); }
};
int main() {
  cout.tie(nullptr);
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  BST<char> t('A');
  int N;
  cin >> N;
  while (N--) {
    char a, b, c;
    cin >> a >> b >> c;
    t.insert(a, b, c);
  }
  t.preOrder();
  cout << '\n';
  t.inOrder();
  cout << '\n';
  t.postOrder();
}