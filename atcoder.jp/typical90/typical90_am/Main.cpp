#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
long long n;
long long ans = 0;

void dfs(Graph &G, vector<int> &dp, int cur, int pre) {
  dp.at(cur) = 1;
  for (auto to : G.at(cur)) {
    if (to == pre) continue;
    dfs(G, dp, to, cur);
    dp.at(cur) += dp.at(to);
    ans += dp.at(to) * (n - dp.at(to));
  }
}

int main() {
  cin >> n;
  Graph G(n);
  vector<pair<int, int>> Q;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    Q.emplace_back(a, b);
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  vector<int> dp(n, 0);

  dfs(G, dp, 0, -1);

  cout << ans << endl;

  return 0;
}
