#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
Graph G;
vector<int> memo;

int dfs(int v) {
  if (memo.at(v) != -1) return memo.at(v);

  int longest = 0;
  for (auto to : G.at(v)) {
    int tmp = dfs(to) + 1;
    if (tmp > longest) longest = tmp;
  }

  memo.at(v) = longest;
  return longest;
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G.at(x).push_back(y);
  }

  // memo[i]: iからの最長の有向パス
  memo.assign(n, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto dist = dfs(i);
    if (dist > ans) ans = dist;
  }

  cout << ans << endl;

  return 0;
}
