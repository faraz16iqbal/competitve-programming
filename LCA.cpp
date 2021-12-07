int up[N][20];
int depth[N];

void get_depth(int node, int par = -1, int l = 1) {
  depth[node] = l;
  for (auto x : adj[node]) {
    if (x != par) {
      get_depth(x, node, l + 1);
    }
  }
}

void binary_lift(int node, int par = -1) {
  up[node][0] = par;
  for (int i = 1; i < 20; i++) {
    if (up[node][i - 1] != -1) {
      up[node][i] =
          up[up[node][i - 1]][i - 1]; // (2 ^ (x-1) + 2 ^ (x-1)) = (2 ^ x)
    } else {
      up[node][i] = -1;
    }
  }
  for (int child : adj[node]) {
    if (child != par)
      binary_lift(child, node);
  }
}

int lift_node(int node, int jumps) {
  if (node == -1 || jumps == 0)
    return node;
  for (int i = 19; i >= 0; i--) {
    if (jumps >= (1 << i)) {
      return lift_node(up[node][i], jumps - (1 << i));
    }
  }
  return -1;
}

// Call getDepth() first
int LCA(int u, int v) {
  if (depth[v] > depth[u])
    swap(u, v);
  u = lift_node(u, depth[u] - depth[v]);
  if (u == v) {
    return u;
  }
  for (int i = 19; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return lift_node(u, 1);
}
