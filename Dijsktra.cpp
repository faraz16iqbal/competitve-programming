vector<bool> visited(n, false);
vector<int> distances(n, INF);
vector<int> parent(n, -1);
priority_queue<pii, vector<pii>, greater<pii>> q;
distances[0] = 0;
q.push({0, 0}); //(distance, node)
while (!q.empty()) {
  int a = q.top().second;
  q.pop();
  if (visited[a]) {
    continue;
  }
  visited[a] = true;
  for (auto u : adj[a]) {
    int b = u.first;
    int w = u.second;
    if (distances[a] + w < distances[b]) {
      distances[b] = distances[a] + w;
      parent[b] = a;
      q.push({distances[b], b});
    }
  }
}
