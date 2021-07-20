#include <bits/stdc++.h>
using namespace std;

int N, Q, root;
using Graph = vector<vector<int>>;
Graph G;
string ans[100001];
map<int, vector<pair<int, int>>> M;
bool is_boss[150001];

void dfs(int u) {
  is_boss[u] = true;
  for (auto [b, i] : M[u]) {
    if (is_boss[b])
      ans[i] = "Yes";
    else
      ans[i] = "No";
  }
  for (auto v : G[u]) {
    dfs(v);
  }
  is_boss[u] = false;
}

int main() {
  cin >> N;
  G.resize(N);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      root = i;
      continue;
    }
    p--;
    G[p].push_back(i);
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    M[a].emplace_back(b, i);
  }

  dfs(root);

  for (int i = 0; i < Q; i++) cout << ans[i] << endl;

  return 0;
}
