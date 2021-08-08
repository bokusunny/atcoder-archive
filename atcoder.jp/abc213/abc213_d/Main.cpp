#include <bits/stdc++.h>
using namespace std;

int N;
using Graph = vector<vector<int>>;
Graph G;
vector<bool> seen;
vector<int> ans;

void dfs(int u, int p = -1) {
  seen[u] = true;
  ans.push_back(u);
  for (auto v : G[u]) {
    if (v == p) continue;
    if (seen[v]) continue;
    dfs(v, u);
    ans.push_back(u);
  }
}

void solve() {
  cin >> N;
  G.resize(N), seen.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (auto &g : G) sort(g.begin(), g.end());

  dfs(0);
  for (auto a : ans) cout << a + 1 << " ";
  cout << endl;
}

int main() {
  solve();

  return 0;
}
