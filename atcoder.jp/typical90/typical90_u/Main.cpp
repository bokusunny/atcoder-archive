#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
void tree_dfs(Graph &graph, vector<bool> &seen, vector<int> &out, int v, int &t) {
  seen.at(v) = true;

  for (auto nxt_v : graph.at(v)) {
    if (seen.at(nxt_v)) continue;
    tree_dfs(graph, seen, out, nxt_v, t);
  }

  out.at(t) = v;
  t++;
}

void tree_dfs2(Graph &graph, vector<bool> &seen, int v, long long &t) {
  seen.at(v) = true;
  t++;

  for (auto nxt_v : graph.at(v)) {
    if (seen.at(nxt_v)) continue;
    tree_dfs2(graph, seen, nxt_v, t);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph graph(n);
  Graph graph2(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph.at(a).push_back(b);
    graph2.at(b).push_back(a);
  }

  vector<bool> seen(n, false);
  vector<int> out(n);
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (seen.at(i)) continue;
    tree_dfs(graph, seen, out, i, t);
  }

  reverse(out.begin(), out.end());

  long long ans = 0;
  seen.assign(n, false);
  for (int i = 0; i < n; i++) {
    auto v = out.at(i);
    if (seen.at(v)) continue;
    long long t = 0;
    tree_dfs2(graph2, seen, v, t);
    ans += t * (t - 1) / 2;
  }

  cout << ans << endl;

  return 0;
}
