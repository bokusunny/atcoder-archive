#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

auto dijkstra(WeightGraph &G, int s) {
  int n = (int)G.size();
  vector<long long> dist(n, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist[s] = 0;

  while (!h.empty()) {
    auto [cd, cv] = h.top();
    h.pop();

    if (cv == s && cd != 0) {
      cout << cd << endl;
      return;
    }
    if (cd > dist[cv]) continue;

    for (auto [nv, w] : G[cv]) {
      long long nd = cd + w;
      if (nv != s && nd >= dist[nv]) continue;

      dist[nv] = nd;
      h.push({nd, nv});
    }
  }

  cout << -1 << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  WeightGraph G(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(Edge(b, c));
  }

  for (int i = 0; i < N; i++) {
    dijkstra(G, i);
  }

  return 0;
}
