#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  vector<int> A_(N);
  for (int i = 0; i < N; i++) cin >> A_[i];
  auto Zahyo = A_;
  sort(Zahyo.begin(), Zahyo.end());
  Zahyo.erase(unique(Zahyo.begin(), Zahyo.end()), Zahyo.end());
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    A[i] = lower_bound(Zahyo.begin(), Zahyo.end(), A_[i]) - Zahyo.begin();
  }

  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back({v});
    G[v].push_back({u});
  }

  segtree<S, op, e> seg(N);
  vector<int> ans(N);
  function<void(int, int)> dfs = [&](int u, int p) {
    auto cached_val = seg.get(A[u]);
    seg.set(A[u], seg.prod(0, A[u]) + 1);
    ans[u] = seg.all_prod();
    for (auto [v] : G[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
    seg.set(A[u], cached_val);
  };
  dfs(0, -1);

  for (auto &a : ans) cout << a << endl;
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
