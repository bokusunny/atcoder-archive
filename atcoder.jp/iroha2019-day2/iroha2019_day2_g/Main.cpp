#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long w;

  Edge(const int to, const long long w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }

  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  const long long INF = 1LL << 60;
  auto dijkstra = [&](const Graph &graph, int s) {
    int n = (int)graph.size();
    vector Dist(n, vector<long long>(K + 1, INF));
    using P = tuple<long long, int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    Dist[s][0] = 0;
    pq.emplace(0LL, s, 0);

    while (!pq.empty()) {
      auto [cd, cv, cc] = pq.top();
      pq.pop();

      if (cd > Dist[cv][cc]) continue;

      for (auto [nv, dd] : graph[cv]) {
        long long nd = cd + dd;
        if (nd >= Dist[nv][cc]) continue;

        Dist[nv][cc] = nd;
        pq.emplace(nd, nv, cc);
      }

      int nc = min(K, cc + X[cv]);
      long long nd = cd + Y[cv];
      if (nd >= Dist[cv][nc]) continue;
      Dist[cv][nc] = nd;
      pq.emplace(nd, cv, nc);
    }

    return Dist;
  };

  auto dist = dijkstra(G, 0);
  if (dist[N - 1][K] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[N - 1][K] << endl;
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
