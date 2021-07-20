#include <bits/stdc++.h>
using namespace std;

int N, M;
using Graph = vector<vector<int>>;
Graph G;
vector<int> grouped, col;
vector<vector<int>> Group;

void dfs1(int u, int p, vector<int>& group) {
  group.push_back(u);
  grouped[u] = true;
  for (auto v : G[u]) {
    if (v == p || grouped[v]) continue;
    dfs1(v, u, group);
  }
}

void grouping() {
  for (int u = 0; u < N; u++) {
    if (grouped[u]) continue;
    vector<int> group;
    dfs1(u, -1, group);
    Group.push_back(group);
  }
}

long long paint(vector<int>& g, int idx) {
  int u = g[idx];
  for (auto v : G[u]) {
    if (col[u] == col[v]) return 0;
  }
  if (idx == (int)g.size() - 1) return 1;

  long long res = 0;
  for (int i = 0; i < 3; i++) {
    col[g[idx + 1]] = i;
    res += paint(g, idx + 1);
    col[g[idx + 1]] = -1;
  }

  return res;
}

int main() {
  cin >> N >> M;
  G.resize(N), grouped.resize(N), col.assign(N, -1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  grouping();

  long long ans = 1;
  for (auto g : Group) {
    col[g[0]] = 0;
    ans *= paint(g, 0) * 3;
    col[g[0]] = -1;
  }

  cout << ans << endl;

  return 0;
}
