#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long w;
};
using Graph = vector<vector<Edge>>;

const long long INF = 1LL << 60;

auto dijkstra(const Graph &G, int s) {
  int N = (int)G.size();
  vector<long long> dist(N, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist[s] = 0;

  while (!h.empty()) {
    auto [cd, cv] = h.top();
    h.pop();

    if (cd > dist[cv]) continue;

    for (auto [nv, w] : G[cv]) {
      long long nd = cd + w;
      if (nd >= dist[nv]) continue;

      dist[nv] = nd;
      h.push({nd, nv});
    }
  }

  return dist;
}

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  Graph G1(n), G2(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    long long a, b;
    cin >> u >> v >> a >> b;
    u--, v--;
    G1[u].push_back({v, a});
    G1[v].push_back({u, a});
    G2[u].push_back({v, b});
    G2[v].push_back({u, b});
  }

  auto CostY = dijkstra(G1, s);
  auto CostS = dijkstra(G2, t);

  vector<long long> Cost(n);  // i番目の料金所で換金した時の最小コスト
  for (int i = 0; i < n; i++) {
    Cost[i] = CostY[i] + CostS[i];
  }

  vector<long long> ans(n);  // i年後に出発した時の最小コスト
  ans[n - 1] = Cost[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    ans[i] = min(ans[i + 1], Cost[i]);
  }

  long long init = 1e15;
  for (int i = 0; i < n; i++) {
    cout << init - ans[i] << endl;
  }
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
