#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
WeightGraph G;
vector<int> dist;

void dfs(int u, int p, int d) {
  dist[u] = d;
  for (auto [v, w] : G[u]) {
    if (v == p) continue;
    dfs(v, u, (d + w) % 2);
  }
}

int main() {
  int N;
  cin >> N;
  G.resize(N), dist.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    w %= 2;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }

  dfs(0, -1, 0);

  for (int i = 0; i < N; i++) cout << dist[i] << endl;

  return 0;
}
