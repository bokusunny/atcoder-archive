#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

#include <atcoder/scc>
using namespace atcoder;

void solve() {
  int N, M;
  cin >> N >> M;
  scc_graph scc_graph(N);
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    scc_graph.add_edge(a, b);
    G[a].emplace_back(b);
  }
  auto scc = scc_graph.scc();

  vector<bool> Seen(N);
  auto dfs = [&](auto dfs, int u) -> void {
    Seen[u] = true;
    for (auto [v] : G[u]) {
      if (Seen[v]) continue;
      dfs(dfs, v);
    }
  };
  int ans = 0;
  for (auto &g : scc) {
    if (Seen[g[0]]) continue;
    dfs(dfs, g[0]);
    ans++;
  }

  cout << ans << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
