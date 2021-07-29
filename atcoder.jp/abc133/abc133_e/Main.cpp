#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int N, K;
using Graph = vector<vector<int>>;
Graph G;

mint dfs(int u, int p, int depth) {
  mint res = 1;
  mint i = K - min(2, depth + 1);
  for (auto v : G[u]) {
    if (v == p) continue;
    res *= i * dfs(v, u, depth + 1);
    i--;
  }
  return res;
}

int main() {
  cin >> N >> K;
  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << (dfs(0, -1, 0) * K).val() << endl;

  return 0;
}
