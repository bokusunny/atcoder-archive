#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;
vector<pair<int, int>> E;
map<pair<int, int>, int> C;
int max_color = 0;

pair<int, int> get_e(int v1, int v2) {
  if (v1 < v2) return {v1, v2};
  return {v2, v1};
}

void dfs(int cv, int pv = 0) {
  int color = 1;
  for (auto nv : G[cv]) {
    if (nv == pv) continue;
    if (color == C[get_e(cv, pv)]) color++;
    C[get_e(cv, nv)] = color;
    max_color = max(max_color, color);
    dfs(nv, cv);
    color++;
  }
}

int main() {
  int N;
  cin >> N;
  G.resize(N), E.resize(N - 1);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    E[i] = {a, b};
  }

  dfs(0);

  cout << max_color << endl;
  for (auto [a, b] : E) cout << C[get_e(a, b)] << endl;

  return 0;
}
