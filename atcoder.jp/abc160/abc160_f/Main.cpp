#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int N;
using Graph = vector<vector<int>>;
Graph G;
vector<mint> dp, ans;
vector<int> SubSize;
vector<mint> factorial(200010, 1);

void dfs1(int u, int p = -1) {
  for (auto v : G[u]) {
    if (v == p) continue;
    dfs1(v, u);
    SubSize[u] += SubSize[v];
    dp[u] *= dp[v];
  }
  dp[u] *= factorial[SubSize[u] - 1];
  for (auto v : G[u]) {
    if (v == p) continue;
    dp[u] /= factorial[SubSize[v]];
  }
}

void dfs2(int u, int p = -1) {
  ans[u] = 1;
  for (auto v : G[u]) {
    ans[u] *= dp[v] / factorial[SubSize[v]];
  }
  ans[u] *= factorial[N - 1];

  for (auto v : G[u]) {
    if (v == p) continue;
    SubSize[u] = N - SubSize[v];
    dp[u] = ans[u] * factorial[SubSize[v]] * factorial[N - SubSize[v] - 1] / factorial[N - 1] / dp[v];
    dfs2(v, u);
  }
}

int main() {
  cin >> N;
  G.resize(N), dp.assign(N, 1), SubSize.assign(N, 1), ans.resize(N);
  for (int i = 2; i < 200001; i++) factorial[i] = factorial[i - 1] * i;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs1(0);
  dfs2(0);

  for (auto a : ans) cout << a.val() << endl;

  return 0;
}
