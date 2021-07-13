#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;
using Graph = vector<vector<int>>;
Graph G;
mint dp[100010][2];  // iを根とする部分木で、その根をjに塗れるものの数
bitset<100010> seen;

void dfs(int u) {
  seen.set(u);

  mint b = 1, w = 1;
  for (auto to : G[u]) {
    if (seen[to]) continue;
    dfs(to);
    b *= dp[to][1];
    w *= (dp[to][0] + dp[to][1]);
  }
  dp[u][0] = b, dp[u][1] = w;
}

int main() {
  int N;
  cin >> N;
  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0);

  cout << (dp[0][0] + dp[0][1]).val() << endl;

  return 0;
}
