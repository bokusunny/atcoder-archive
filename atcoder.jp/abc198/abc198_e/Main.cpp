#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
void tree_dfs(Graph &graph, vector<bool> &seen, int v, vector<int> &C, vector<int> &seen_cnt, set<int> &good_v) {
  auto c = C.at(v);
  if (seen_cnt.at(c) == 0) good_v.insert(v);
  seen_cnt.at(c)++;
  seen.at(v) = true;

  for (auto nxt_v : graph.at(v)) {
    if (seen.at(nxt_v)) continue;
    tree_dfs(graph, seen, nxt_v, C, seen_cnt, good_v);
  }

  seen_cnt.at(c)--;
}

int main() {
  int n;
  cin >> n;
  vector<int> C(n);
  for (auto &c : C) cin >> c;
  Graph graph(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  set<int> good_v;
  vector<int> seen_cnt(100001, 0);
  vector<bool> seen(n, false);
  tree_dfs(graph, seen, 0, C, seen_cnt, good_v);

  for (auto v : good_v) {
    cout << v + 1 << endl;
  }

  return 0;
}
