#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long weight;
};
using Graph = vector<vector<Edge>>;
const int INF = 1 << 30;

void solve() {
  int N, M, L;
  cin >> N >> M >> L;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--, b--;
    if (c > L) continue;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  auto get_dist = [&](int s) {
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<pair<int, int>> Dist(N, {INF, INF});
    pq.emplace(0, 0, s);
    Dist[s] = {0, 0};

    while (!pq.empty()) {
      auto [cd, used, cv] = pq.top();
      pq.pop();

      if (make_pair(cd, used) > Dist[cv]) continue;

      for (auto [nv, w] : G[cv]) {
        pair<int, int> p = {-1, -1};
        if (used + w > L) {
          int nd = cd + 1;
          int nused = w;
          p = {nd, nused};
        } else {
          int nd = cd;
          int nused = used + w;
          p = {nd, nused};
        }
        assert(p.first != -1);
        if (p < Dist[nv]) {
          pq.emplace(p.first, p.second, nv);
          Dist[nv] = p;
        }
      }
    }

    vector<int> res(N);
    for (int i = 0; i < N; i++) {
      res[i] = Dist[i].first;
    }

    return res;
  };

  vector<vector<int>> Dist;
  for (int s = 0; s < N; s++) {
    auto dist = get_dist(s);
    Dist.push_back(dist);
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    if (Dist[s][t] == INF) {
      cout << -1 << endl;
    } else {
      cout << Dist[s][t] << endl;
    }
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
