class SegTree {
public:
  int leftmost, rightmost;
  SegTree *lChild, *rChild;
  int sum = 0;

  SegTree(int leftmost, int rightmost, vector<int> &arr) {
    this->leftmost = leftmost;
    this->rightmost = rightmost;
    if (leftmost == rightmost) // leaf node
    {
      sum = arr[leftmost];
    } else // 2 children
    {
      int mid = (leftmost + rightmost) / 2;
      lChild = new SegTree(leftmost, mid, arr);
      rChild = new SegTree(mid + 1, rightmost, arr);
      recalc();
    }
  }

  void pointUpdate(int index, int newVal) {
    if (leftmost == rightmost) {
      sum = newVal;
      return;
    }
    if (index <= lChild->rightmost)
      lChild->pointUpdate(index, newVal);
    else
      rChild->pointUpdate(index, newVal);
    recalc();
  }

  void recalc() {
    if (leftmost == rightmost)
      return;
    sum = (lChild->sum + rChild->sum);
  }

  int rangeSum(int l, int r) {
    // entirely disjoint
    if (l > rightmost || r < leftmost)
      return 0;
    // covers us
    if (l <= leftmost && r >= rightmost)
      return sum;
    // case 3:  we don't know
    return (lChild->rangeSum(l, r) + rChild->rangeSum(l, r));
  }
};
