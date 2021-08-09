#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

int to_num(int a, int b, int n) {
  if (a > b) swap(a, b);
  return n * (n - 1) / 2 - (n - a) * (n - a - 1) / 2 + b - a - 1;
}

vector<int> topo_sort(const Graph &G) {  // bfs
  vector<int> ans;
  int n = (int)G.size();
  vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
  for (int i = 0; i < n; i++) {  // 次数を数えておく
    for (auto e : G[i]) {
      ind[e.to]++;
    }
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
    if (ind[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {  // 幅優先探索
    int now = que.front();
    ans.push_back(now);
    que.pop();
    for (auto e : G[now]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        que.push(e.to);
      }
    }
  }

  return ans;
}

void solve() {
  int N;
  cin >> N;
  int vnum = N * (N - 1) / 2;
  Graph G(vnum);
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      cin >> A[i][j];
      A[i][j]--;
      if (j == 0) continue;
      auto prev = to_num(i, A[i][j - 1], N);
      auto cur = to_num(i, A[i][j], N);
      G[prev].push_back(Edge{cur});
    }
  }

  auto V = topo_sort(G);
  if ((int)V.size() != vnum) {
    cout << -1 << endl;
    return;
  }

  vector<int> dp(vnum);
  function<int(int)> dfs = [&](int u) {
    if (dp[u] != 0) return dp[u];
    for (auto [v] : G[u]) {
      dp[u] = max(dp[u], dfs(v));
    }
    dp[u]++;
    return dp[u];
  };

  for (auto v : V) {
    if (dp[v] == 0) dfs(v);
  }

  int ans = 0;
  for (auto val : dp) ans = max(ans, val);

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
