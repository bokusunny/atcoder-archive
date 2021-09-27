#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
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
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<long long> ans(N);
  vector<int> Sub(N, 1);
  function<void(int, int, int)> dfs1 = [&](int u, int p, int depth) {
    ans[0] += depth;
    for (auto [v] : G[u]) {
      if (v == p) continue;
      dfs1(v, u, depth + 1);
      Sub[u] += Sub[v];
    }
  };
  dfs1(0, -1, 0);

  function<void(int, int)> dfs2 = [&](int u, int p) {
    for (auto [v] : G[u]) {
      if (v == p) continue;
      ans[v] = ans[u];
      ans[v] += N - Sub[v];
      ans[v] -= Sub[v];
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
