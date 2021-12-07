struct SparseTable {
  vector<vector<int>> table;
  vector<int> logValues;
  int n;
  int maxLog;
  vector<int> arr;

  SparseTable(int n1, vector<int> &a) {
    n = n1;
    arr = a;
    table.resize(n);
    maxLog = log2(n);
    for (int i = 0; i < n; i++) {
      table[i].resize(maxLog + 1);
    }
    logValues.resize(n + 1);
    logValues[1] = 0;
    for (int i = 2; i <= n; i++) {
      logValues[i] = logValues[i / 2] + 1;
    }
    build();
  }

  void build() {
    for (int L = n - 1; L >= 0; L--) {
      for (int W = 0; W < 25; W++) {
        int R = L + (1 << W);
        if (R >= n)
          break;
        if (W == 0)
          table[L][0] = arr[L];
        else
          table[L][W] = min(table[L][W - 1], table[L + (1 << (W - 1))][W - 1]);
      }
    }
  }
  int query(int L, int R) { // O(1)
    int length = R - L + 1;
    int k = logValues[length];
    return min(table[L][k], table[R - (1 << k) + 1][k]);
  }
};
