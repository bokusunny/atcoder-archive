#include <bits/stdc++.h>
using namespace std;

int N, M;
using Graph = vector<vector<int>>;
Graph G;
long long dp[100010], ans[100010];

void dfs1(int u, int p = -1) {
  long long tmp = 1;

  for (auto v : G[u]) {
    if (v == p) continue;
    dfs1(v, u);
    tmp *= (dp[v] + 1);
    tmp %= M;
  }

  dp[u] = tmp;
}

void dfs2(int u, int p = -1) {
  ans[u] = 1;
  for (auto v : G[u]) {
    ans[u] *= (dp[v] + 1);
    ans[u] %= M;
  }

  int sz = (int)G[u].size();
  vector<long long> l(sz), r(sz);
  for (int i = 0; i < sz; i++) {
    l[i] = r[i] = dp[G[u][i]] + 1;
    l[i] %= M, r[i] %= M;
  }
  for (int i = 1; i < sz; i++) {
    l[i] *= l[i - 1];
    l[i] %= M;
  }
  for (int i = sz - 2; i >= 0; i--) {
    r[i] *= r[i + 1];
    r[i] %= M;
  }

  for (int i = 0; i < sz; i++) {
    if (G[u][i] == p) continue;
    dp[u] = 1;
    if (i > 0) dp[u] *= l[i - 1], dp[u] %= M;
    if (i < sz - 1) dp[u] *= r[i + 1], dp[u] %= M;
    dfs2(G[u][i], u);
  }
}

int main() {
  cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs1(0);
  dfs2(0);

  for (int i = 0; i < N; i++) cout << ans[i] << endl;

  return 0;
}
