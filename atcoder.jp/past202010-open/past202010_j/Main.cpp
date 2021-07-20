#include <bits/stdc++.h>
using namespace std;

int N, M;
struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
WeightGraph G;
const long long INF = 1LL << 60;

auto dijkstra(int s) {
  vector<long long> dist(N + 6, INF);
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

  cout << dist[N - 1] << endl;
}

int main() {
  cin >> N >> M;
  G.resize(N + 6);

  long long AB, AC, BC;
  cin >> AB >> AC >> BC;
  G[N].push_back(Edge(N + 4, AB));
  G[N].push_back(Edge(N + 5, AC));
  G[N + 1].push_back(Edge(N + 3, AB));
  G[N + 1].push_back(Edge(N + 5, BC));
  G[N + 2].push_back(Edge(N + 3, AC));
  G[N + 2].push_back(Edge(N + 4, BC));
  string S;
  cin >> S;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'A') {
      G[i].push_back(Edge(N, 0));
      G[N + 3].push_back(Edge(i, 0));
    } else if (S[i] == 'B') {
      G[i].push_back(Edge(N + 1, 0));
      G[N + 4].push_back(Edge(i, 0));
    } else if (S[i] == 'C') {
      G[i].push_back(Edge(N + 2, 0));
      G[N + 5].push_back(Edge(i, 0));
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(Edge(b, c));
    G[b].push_back(Edge(a, c));
  }

  dijkstra(0);

  return 0;
}
