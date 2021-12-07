vector<int> adj[N];
vector<int> deg(N);

vector<int> topological_sort(int n) {
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j : adj[i])
      deg[j]++;
  }

  for (int i = 0; i < n; i++) {
    if (deg[i] == 0)
      ans.push_back(i);
  }

  int q = 0;
  while (q < int(ans.size())) {
    int cur = ans[q++];
    for (int next : adj[cur]) {
      if (--deg[next] == 0)
        ans.push_back(next);
    }
  }
  return ans;
}