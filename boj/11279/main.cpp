#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename T, typename = void>
struct is_iterator {
  static constexpr bool value = false;
};

template <typename T>
struct is_iterator<
    T, typename std::enable_if<!std::is_same<
           typename std::iterator_traits<T>::value_type, void>::value>::type> {
  static constexpr bool value = true;
};

template <typename T, typename Comp = std::less<T> >
class Heap {
 private:
  std::vector<T> __heap;
  static constexpr int root = 1;
  int __end;
  Comp __comp;

 public:
  Heap() : __end(0), __comp(Comp()) { __heap.push_back(0); }
  Heap(size_t size) : __end(0), __comp(Comp()) {
    __heap.reserve(size + 1);
    __heap.push_back(0);
  }
  Heap(const Heap& src)
      : __end(src.__end), __heap(src.__heap), __comp(src.__comp) {}
  Heap(Heap&& src) : __end(src.__end), __heap(src.__heap), __comp(src.comp) {}
  template <typename InputIterator>
  Heap(InputIterator first,
       typename std::enable_if<is_iterator<InputIterator>::value,
                               InputIterator>::type last)
      : __end(0), __comp(Comp()) {
    static_assert(
        !std::is_same<
            typename std::iterator_traits<InputIterator>::iterator_category,
            std::input_iterator_tag>::value);
    __heap.reserve(std::distance(first, last) + 1);
    __heap.push_back(0);
    for (; first != last; ++first) push(*first);
  }
  int leftChildIdx(int cur) { return cur * 2; }
  int rightChildIdx(int cur) { return cur * 2 + 1; }
  int parentIdx(int cur) { return cur / 2; }
  void push(T val) {
    __heap.push_back(val);
    ++__end;
    int cur = __end;
    int parent = parentIdx(cur);
    while (__comp(__heap[cur], __heap[parent]) && cur != 1) {
      std::swap(__heap[cur], __heap[parent]);
      cur = parent;
      parent = parentIdx(cur);
    }
  }
  void pop() {
    if (!__end) return;
    if (__end == 1) {
      __heap.pop_back();
      __end = 0;
      return;
    }
    std::swap(__heap[1], __heap[__end]);
    __heap.pop_back();
    --__end;
    int cur = 1;
    int left, right;
    while (cur <= __end / 2) {
      left = leftChildIdx(cur), right = rightChildIdx(cur);
      int next = __end;
      if (right <= __end)
        next = __comp(__heap[left], __heap[right]) ? left : right;
      if (__comp(__heap[cur], __heap[next])) break;
      std::swap(__heap[cur], __heap[next]);
      cur = next;
    }
  };
  typename std::vector<T>::iterator find(const T val) {}
  void clear() { __heap.clear(); }
  size_t size() { return __end; }
  T& operator[](size_t idx) { return __heap[idx]; }
  T* begin() { return &__heap[1]; }
  T* end() { return &__heap[__end + 1]; }
  T& front() { return (__end == 0) ? __heap[0] : __heap[1]; }
  bool empty() { return __end == 0; }
  ~Heap() {}
};

using namespace std;
int main() {
  cin.ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int input;
  Heap<int, greater<int> > h;
  while (N--) {
    cin >> input;
    if (!input) {
      cout << h.front() << '\n';
      h.pop();
    } else
      h.push(input);
  }
}