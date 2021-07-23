#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

struct Edge {
  int to;
  long long weight;
  Edge(int t, long long w) : to(t), weight(w) {}
};
using WeightGraph = vector<vector<Edge>>;
WeightGraph G;
vector<long long> Xor;
vector<int> ocnt(60);

void dfs(int u, int p = -1) {
  for (auto [v, w] : G[u]) {
    if (v == p) continue;
    Xor[v] = Xor[u] ^ w;
    dfs(v, u);
  }
}

int main() {
  int N;
  cin >> N;
  G.resize(N), Xor.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    long long w;
    cin >> w;
    u--, v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  dfs(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 60; j++) {
      if (Xor[i] >> j & 1) ocnt[j]++;
    }
  }

  mint ans = 0;
  for (int i = 0; i < 60; i++) {
    mint tmp = (1LL << i);
    ans += tmp * ocnt[i] * (N - ocnt[i]);
  }

  cout << ans.val() << endl;

  return 0;
}
