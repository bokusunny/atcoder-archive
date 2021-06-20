#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
void tree_dfs(Graph &graph, vector<bool> &seen, int v, int &cnt) {
  seen.at(v) = true;
  cnt++;

  for (auto nxt_v : graph.at(v)) {
    if (seen.at(nxt_v)) continue;
    tree_dfs(graph, seen, nxt_v, cnt);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  const int max = 200001;
  Graph G(max);
  set<int> V;
  for (int i = 0; i < n / 2; i++) {
    int left = A.at(i), right = A.at(n - 1 - i);
    G.at(left).push_back(right);
    G.at(right).push_back(left);
    V.insert(left), V.insert(right);
  }

  int ans = 0;
  vector<bool> seen(max);
  for (int i = 0; i < max; i++) {
    if (!seen.at(i) && V.count(i)) {
      int cnt = 0;
      tree_dfs(G, seen, i, cnt);
      ans += cnt - 1;
    }
  }

  cout << ans << endl;

  return 0;
}
