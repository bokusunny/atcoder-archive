#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;
struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back({b});
    G[b].push_back({a});
  }

  vector dp(N, vector<mint>(2, 1));  // dp[i][is_black]
  function<void(int, int)> dfs = [&](int u, int p) {
    if (u != 0 && (int)G[u].size() == 1) return;

    for (auto [v] : G[u]) {
      if (v == p) continue;
      dfs(v, u);
      dp[u][1] *= dp[v][0];
      dp[u][0] *= dp[v][0] + dp[v][1];
    }
  };

  dfs(0, -1);

  cout << accumulate(dp[0].begin(), dp[0].end(), (mint)0).val() << endl;
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
