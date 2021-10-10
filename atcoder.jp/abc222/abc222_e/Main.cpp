#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(M);
  for (int i = 0; i < M; i++) cin >> A[i], A[i]--;
  Graph G(N);
  vector ID(N, vector<int>(N, -1));
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    ID[a][b] = ID[b][a] = i;
  }

  auto get_direct_path = [](Graph &graph, int sv, int gv) {
    vector<int> Vs;
    bool found = false;
    auto dfs = [&](auto dfs, int u, int p, int target, bool &found, vector<int> &vs) -> void {
      vs.push_back(u);
      if (u == target) {
        found = true;
        return;
      }
      for (auto [v] : graph[u]) {
        if (v == p) continue;
        dfs(dfs, v, u, target, found, vs);
        if (found) return;
      }
      vs.pop_back();
    };
    dfs(dfs, sv, -1, gv, found, Vs);
    return Vs;
  };

  vector<int> Cnt(N - 1);
  for (int i = 1; i < M; i++) {
    auto Vs = get_direct_path(G, A[i], A[i - 1]);
    for (int j = 1; j < (int)Vs.size(); j++) {
      Cnt[ID[Vs[j - 1]][Vs[j]]]++;
    }
  }

  const int base = 100100;
  vector dp(N, vector<mint>(base * 2));
  dp[0][base] = 1;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < base * 2; j++) {
      if (dp[i][j].val() == 0) continue;
      dp[i + 1][j + Cnt[i]] += dp[i][j];
      dp[i + 1][j - Cnt[i]] += dp[i][j];
    }
  }

  cout << dp[N - 1][base + K].val() << endl;
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
