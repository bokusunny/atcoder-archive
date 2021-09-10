#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int fee;
  int cost;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M, S;
  cin >> N >> M >> S;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int U, V, A, B;
    cin >> U >> V >> A >> B;
    U--, V--;
    G[U].push_back({V, A, B});
    G[V].push_back({U, A, B});
  }

  vector<int> C(N), D(N);
  for (int i = 0; i < N; i++) cin >> C[i] >> D[i];

  const int MX_COIN = 2500;
  const long long INF = 1LL << 60;
  vector Dist(N, vector<long long>(MX_COIN + 1, INF));
  using T = tuple<long long, int, int>;  // dist, u, coin
  priority_queue<T, vector<T>, greater<T>> pq;

  pq.emplace(0LL, 0, min(S, MX_COIN));
  Dist[0][min(S, MX_COIN)] = 0LL;
  while (!pq.empty()) {
    auto [cd, cv, coin] = pq.top();
    pq.pop();

    if (cd > Dist[cv][coin]) continue;

    for (auto [nv, fee, dd] : G[cv]) {
      long long nd = cd + dd;
      int ncoin = coin - fee;
      if (ncoin < 0 || Dist[nv][ncoin] <= nd) continue;
      Dist[nv][ncoin] = nd;
      pq.emplace(nd, nv, ncoin);
    }

    long long nd = cd + D[cv];
    int ncoin = min(coin + C[cv], MX_COIN);
    if (Dist[cv][ncoin] > nd) {
      Dist[cv][ncoin] = nd;
      pq.emplace(nd, cv, ncoin);
    }
  }

  for (int i = 1; i < N; i++) {
    long long ans = INF;
    for (auto d : Dist[i]) ans = min(ans, d);
    cout << ans << endl;
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
