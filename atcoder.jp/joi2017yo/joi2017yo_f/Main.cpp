#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int weight;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      t = 2;
    } else if (t == 2) {
      t = 1;
    }
    T[i] = t;
  }
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int A, B, D;
    cin >> A >> B >> D;
    A--, B--;
    G[A].push_back({B, D});
    G[B].push_back({A, D});
  }

  const int INF = 1 << 30;
  vector dist(N, vector(2, vector<int>(X + 1, INF)));
  using Tup = tuple<int, int, int, int>;  // dist, v, is_last_hot, time
  priority_queue<Tup, vector<Tup>, greater<Tup>> h;
  h.push({0, 0, 0, 0});
  dist[0][0][0] = 0;

  while (!h.empty()) {
    auto [cd, cv, is_last_hot, time] = h.top();
    h.pop();

    if (cd > dist[cv][is_last_hot][time]) continue;

    for (auto [nv, dd] : G[cv]) {
      int nd = cd + dd;

      if (T[nv] == 2 || T[nv] == is_last_hot) {
        int nt = T[nv] == 2 ? min(X, time + dd) : 0;
        if (nd >= dist[nv][is_last_hot][nt]) continue;

        dist[nv][is_last_hot][nt] = nd;
        h.emplace(nd, nv, is_last_hot, nt);
      } else {
        if (time + dd < X) continue;
        if (nd >= dist[nv][!is_last_hot][0]) continue;

        dist[nv][!is_last_hot][0] = nd;
        h.emplace(nd, nv, !is_last_hot, 0);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j <= X; j++) {
      ans = min(ans, dist[N - 1][i][j]);
    }
  }

  cout << ans << endl;
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
