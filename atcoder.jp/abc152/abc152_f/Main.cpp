#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, id;
};

int N, M;
using Graph = vector<vector<Edge>>;
Graph G;
vector<bitset<50>> white;  // white[i] := i番目の条件で白に染まる辺の集合

bool dfs(int u, int p, int g, int i) {
  if (u == g) return true;

  for (auto [v, id] : G[u]) {
    if (v == p) continue;
    if (dfs(v, u, g, i)) {
      white[i].set(id);
      return true;
    }
  }

  return false;
}

int main() {
  cin >> N;
  G.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(Edge{b, i});
    G[b].push_back(Edge{a, i});
  }
  cin >> M;
  white.resize(M);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    dfs(u, -1, v, i);
  }

  long long ans = 1LL << (N - 1);
  for (int msk = 1; msk < 1 << M; msk++) {
    int cnt = 0;
    bitset<50> E;
    for (int i = 0; i < M; i++) {
      if ((msk >> i & 1) == 0) continue;
      cnt++;
      E |= white[i];
    }
    long long tmp = 1;
    for (int i = 0; i < N - 1 - (int)E.count(); i++) tmp *= 2;

    if (cnt % 2 == 0) {
      ans += tmp;
    } else {
      ans -= tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
