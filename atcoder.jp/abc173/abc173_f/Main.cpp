#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back({v});
    G[v].push_back({u});
  }

  long long ans = 0;
  for (int u = 0; u < N; u++) {
    ans += 1LL * (N - u + 1) * (N - u) / 2;
    for (auto [v] : G[u]) {
      if (u > v) continue;
      ans -= 1LL * (u + 1) * (N - v);
    }
  }

  cout << ans << endl;
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
