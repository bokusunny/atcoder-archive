#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
WeightGraph G;

#include <bits/stdc++.h>
using namespace std;

int N, M;
const long long INF = 1LL << 60;

auto dijkstra(int s) {
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

  if (dist[N - 1] != INF)
    cout << dist[N - 1] << endl;
  else
    cout << -1 << endl;
}

int main() {
  cin >> N >> M;
  G.resize(N);

  for (int i = N - 1; i >= 1; i--) G[i].push_back({i - 1, 0});
  for (int i = 0; i < M; i++) {
    int L, R, C;
    cin >> L >> R >> C;
    L--, R--;
    G[L].push_back({R, C});
  }

  dijkstra(0);

  return 0;
}
