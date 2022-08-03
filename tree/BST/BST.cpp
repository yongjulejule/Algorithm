#include <algorithm>
#include <iostream>
#include <memory>

template <typename T>
struct Node {
  T data;
  Node* left;
  Node* right;
  Node* parent;
  Node() : data(T()), left(nullptr), right(nullptr), parent(nullptr) {}
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

  NodePtr_t leftChild(NodePtr_t cur) { return cur->left; }
  NodePtr_t rightChild(NodePtr_t cur) { return cur->right; }

 public:
  BST() : __root(nullptr) {}

  NodePtr_t const getRoot() { return __root; }

  NodePtr_t newNode(T& val = T()) {
    NodePtr_t node = alloc::allocate(__a, 1);
    alloc::construct(__a, node, Node_t());
    node->data = val;
    return node;
  }

  bool empty() { return __root == nullptr; }

  void constructNode(NodePtr_t p, T& val, bool isLeft) {
    if (isLeft) {
      p->left = newNode(val);
    } else {
      p->right = newNode(val);
    }
  }
  void insert(T& val) {
    if (empty()) {
      __root = newNode(val);
      return;
    }
    NodePtr_t tmp = __root;
    NodePtr_t parent = tmp->parent;
    while (tmp) {
      parent = tmp;
      if (tmp->data > val)
        tmp = tmp->left;
      else
        tmp = tmp->right;
    }
    constructNode(parent, val, parent->data > val);
  }
  void deleteTree(NodePtr_t cur) {
    if (cur == nullptr) return;
    deleteTree(cur->left);
    deleteTree(cur->right);
    alloc::destroy(__a, cur);
    alloc::deallocate(__a, cur, 1);
  }
  void preOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    std::cout << cur->data << '\n';
    preOrder(cur->left);
    preOrder(cur->right);
  }
  void postOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    postOrder(cur->left);
    postOrder(cur->right);
    std::cout << cur->data << '\n';
  }
  void inOrder(NodePtr_t cur) {
    if (cur == nullptr) return;
    inOrder(cur->left);
    std::cout << cur->data << '\n';
    inOrder(cur->right);
  }
  ~BST() { deleteTree(__root); }
};