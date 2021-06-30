#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  long long k;
  Edge(int t, long long w, long long k) : to(t), weight(w), k(k) {}
};
using WeightGraph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

auto dijkstra(WeightGraph &G, int s, int g) {
  int n = (int)G.size();
  vector<long long> dist(n, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> h;
  h.push({0, s});
  dist[s] = 0;

  while (!h.empty()) {
    auto [cd, cv] = h.top();
    h.pop();

    if (cd > dist[cv]) continue;

    for (auto [nv, w, k] : G[cv]) {
      long long nd = (cd + k - 1) / k * k + w;
      if (nd >= dist[nv]) continue;

      dist[nv] = nd;
      h.push({nd, nv});
    }
  }

  if (dist[g] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[g] << endl;
  }
}

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  X--, Y--;
  WeightGraph G(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    long long T, K;
    cin >> T >> K;
    G[A].push_back(Edge(B, T, K));
    G[B].push_back(Edge(A, T, K));
  }

  dijkstra(G, X, Y);

  return 0;
}
