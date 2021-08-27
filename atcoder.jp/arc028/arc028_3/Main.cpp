#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 1; i <= N - 1; i++) {
    int p;
    cin >> p;
    G[i].push_back({p});
    G[p].push_back({i});
  }

  vector<int> dp(N);
  function<int(int, int)> dfs1 = [&](int u, int p) {
    auto res = 1;
    for (auto &[v] : G[u]) {
      if (v == p) continue;
      res += dfs1(v, u);
    }
    return dp[u] = res;
  };
  dfs1(0, -1);

  vector<int> ans(N);
  function<void(int, int)> dfs2 = [&](int u, int p) {
    ans[u] = max(ans[u], N - dp[u]);
    for (auto &[v] : G[u]) {
      if (v == p) continue;
      ans[u] = max(ans[u], dp[v]);
      dfs2(v, u);
    }
  };
  dfs2(0, -1);

  for (auto &a : ans) cout << a << endl;
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
