#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back({v});
  }
  int S, T;
  cin >> S >> T;
  S--, T--;

  queue<pair<int, int>> q;
  const int INF = 1 << 30;
  vector Dist(N, vector<int>(3, INF));
  Dist[S][0] = 0;
  q.emplace(S, 0);
  while (!q.empty()) {
    auto [u, mo] = q.front();
    q.pop();
    for (auto [v] : G[u]) {
      if (Dist[v][(mo + 1) % 3] != INF) continue;
      Dist[v][(mo + 1) % 3] = Dist[u][mo] + 1;
      q.emplace(v, (mo + 1) % 3);
    }
  }

  if (Dist[T][0] == INF) {
    cout << -1 << endl;
  } else {
    assert(Dist[T][0] % 3 == 0);
    cout << Dist[T][0] / 3 << endl;
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
