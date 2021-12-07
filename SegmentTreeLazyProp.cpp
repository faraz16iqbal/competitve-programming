class LazySegTree {
public:
  LazySegTree *lchild, *rchild;
  int leftmost, rightmost;
  int sum;
  int lazy = 0;
  LazySegTree(int leftmost, int rightmost, vector<int> &v) {
    this->leftmost = leftmost;
    this->rightmost = rightmost;
    if (leftmost == rightmost) // at leaf
    {
      sum = v[leftmost];
      return;
    }
    int mid = (leftmost + rightmost) / 2;
    lchild = new LazySegTree(leftmost, mid, v);
    rchild = new LazySegTree(mid + 1, rightmost, v);
    recalc();
  }
  void recalc() // recalculates sum for the segment
  {
    if (leftmost == rightmost)
      return;
    sum = lchild->sum + rchild->sum;
  }
  void pointUpdate(int index, int val) {
    updateLazy();
    if (leftmost == rightmost) {
      sum += val;
      return;
    }
    int mid = (leftmost + rightmost) / 2;
    if (index <= mid)
      lchild->pointUpdate(index, val);
    else
      rchild->pointUpdate(index, val);
    recalc();
  }
  bool leaf() { return leftmost == rightmost; }
  void updateLazy() {
    if (this->lazy != 0) {
      this->sum += lazy * (rightmost - leftmost + 1);
      if (!leaf()) {
        lchild->lazy += lazy;
        rchild->lazy += lazy;
      }
      lazy = 0;
    }
  }
  void rangeUpdate(int left, int right, int val) {
    updateLazy();
    if (right < leftmost or left > rightmost)
      return;
    if (right >= rightmost and leftmost >= left) {
      sum += val * (rightmost - leftmost + 1);
      if (!leaf()) {
        lchild->lazy += val;
        rchild->lazy += val;
      }
      return;
    }
    lchild->rangeUpdate(left, right, val);
    rchild->rangeUpdate(left, right, val);
    recalc();
    return;
  }
  int rangeSum(int left, int right) {
    if (right < leftmost or left > rightmost)
      return 0;
    updateLazy();
    if (right >= rightmost and left <= leftmost)
      return sum;
    return lchild->rangeSum(left, right) + rchild->rangeSum(left, right);
  }
};