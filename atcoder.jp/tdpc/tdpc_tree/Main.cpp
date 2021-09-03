#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

struct ModFact {
 private:
  vector<long long> Val;

 public:
  ModFact(int size = 1 << 20, int mod = 1e9 + 7) : Val(size + 1, 0) {
    Val[0] = Val[1] = 1;
    for (int i = 2; i <= size; i++) {
      Val[i] = 1LL * Val[i - 1] * i;
      Val[i] %= mod;
    }
  }

  long long get(int n) { return Val[n]; }
};

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back({b});
    G[b].push_back({a});
  }

  ModFact Fact(1 << 10);

  vector<int> dp1(N, 1);   // iを頂点とする部分木に属する頂点の個数
  vector<mint> dp2(N, 1);  // iを頂点とする部分木に辺を描くパターン数
  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (auto [v] : G[u]) {
      if (v == p) continue;
      dfs1(v, u);
      dp1[u] += dp1[v];
      dp2[u] *= dp2[v];
    }
    dp2[u] *= Fact.get(dp1[u] - 1);
    for (auto [v] : G[u]) {
      if (v == p) continue;
      dp2[u] /= Fact.get(dp1[v]);
    }
  };

  dfs1(0, -1);

  mint ans = 0;
  function<void(int, int)> dfs2 = [&](int u, int p) {
    mint tmp = Fact.get(N - 1);
    for (auto [v] : G[u]) {
      tmp *= dp2[v];
      tmp /= Fact.get(dp1[v]);
    }
    ans += tmp;

    for (auto [v] : G[u]) {
      if (v == p) continue;
      dp1[u] = N - dp1[v];
      dp2[u] = tmp / dp2[v];
      dp2[u] *= Fact.get(dp1[v]);
      dp2[u] /= Fact.get(N - 1);
      dp2[u] *= Fact.get(N - 1 - dp1[v]);
      dfs2(v, u);
    }
  };
  dfs2(0, -1);

  ans /= 2;
  cout << ans.val() << endl;
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
