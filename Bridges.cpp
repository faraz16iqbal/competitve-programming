int low[N], tin[N], point[N], vis[N];
int timer = 0;

void cutpoints(int u, int p = -1) {
  vis[u] = 1;
  tin[u] = low[u] = timer++;
  int children = 0;
  for (int x : adj[u]) {
    if (x == p)
      continue;
    if (vis[x]) {
      low[u] = min(low[u], tin[x]);
    } else {
      cutpoints(x, u);
      low[u] = min(low[u], low[x]);
      if (low[x] >= tin[u] && p != -1) {
        IS_CUTPOINT(v, to);
      }
      if (low[to] > tin[v])
        IS_BRIDGE(v, to);
      ++children;
    }
  }
  if (p == -1 && children > 1) {
    IS_CUTPOINT(v, to);
  }
}