#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;
using Graph = vector<vector<int>>;
Graph G;
char C[100010];
mint memo[100010][3];  // 0: aのみ、 1: bのみ、　2: 両方
bitset<100010> seen;

void dfs(int u) {
  seen.set(u);
  int c = C[u] - 'a';

  mint same = 1, all = 1;
  for (auto v : G[u]) {
    if (seen[v]) continue;
    dfs(v);

    same *= (memo[v][c] + memo[v][2]);
    all *= (memo[v][0] + memo[v][1] + 2 * memo[v][2]);
  }
  mint both = all - same;
  memo[u][c] = same, memo[u][2] = both;
}

int main() {
  int N;
  cin >> N;
  G.resize(N);
  bool is_a_seen, is_b_seen;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    if (C[i] == 'a')
      is_a_seen = true;
    else
      is_b_seen = true;
  }
  if (!is_a_seen || !is_b_seen) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0);

  cout << memo[0][2].val() << endl;

  return 0;
}
