#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
const int INF = 1 << 30;

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N), rev(N);
  vector<int> S(M), T(M);
  for (int i = 0; i < M; i++) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    G[s].push_back({t});
    rev[t].push_back({s});
    S[i] = s, T[i] = t;
  }

  auto bfs = [&](Graph &graph, int sv) {
    const int inf = 1 << 30;
    vector<int> Dist(N, INF);
    queue<int> que;
    Dist[sv] = 0;
    que.push(sv);

    while (!que.empty()) {
      auto cv = que.front();
      que.pop();
      for (auto [nv] : graph[cv]) {
        if (Dist[nv] != inf) continue;
        Dist[nv] = Dist[cv] + 1;
        que.push(nv);
      }
    }

    return Dist;
  };

  auto dist = bfs(G, 0);
  if (dist[N - 1] == INF) {
    for (int i = 0; i < M; i++) {
      cout << -1 << endl;
    }
    return;
  }

  set<pair<int, int>> Edges;
  queue<int> q;
  q.push(N - 1);
  int cur = dist[N - 1];
  while (cur > 0) {
    auto u = q.front();
    q.pop();
    for (auto [v] : rev[u]) {
      if (dist[v] == cur - 1) {
        Edges.emplace(v, u);
        cur--;
        q.emplace(v);
        break;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    if (Edges.count({S[i], T[i]})) {
      Graph G2(N);
      for (int j = 0; j < M; j++) {
        if (i == j) continue;
        G2[S[j]].push_back({T[j]});
      }
      auto dis = bfs(G2, 0);
      if (dis[N - 1] == INF) {
        cout << -1 << endl;
      } else {
        cout << dis[N - 1] << endl;
      }
    } else {
      cout << dist[N - 1] << endl;
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
