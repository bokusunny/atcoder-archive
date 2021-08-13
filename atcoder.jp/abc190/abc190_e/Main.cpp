#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
const int INF = 1000000001;

int bfs(Graph &G, int s, int g) {
  int N = (int)G.size();
  vector<int> dist(N, INF);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto [v] : G.at(u)) {
      if (dist.at(v) != INF) continue;

      dist.at(v) = dist.at(u) + 1;
      q.push(v);
    }
  }

  return dist[g];
}

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back({B});
    G[B].push_back({A});
  }

  int K;
  cin >> K;
  vector<int> C(K);
  for (int i = 0; i < K; i++) cin >> C[i], C[i]--;

  vector<vector<int>> Dist(K, vector<int>(K));
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      auto d = bfs(G, C[i], C[j]);
      if (d == INF) {
        cout << -1 << endl;
        return;
      }
      Dist[i][j] = d;
    }
  }

  vector<vector<int>> dp(1 << K, vector<int>(K, INF));
  for (int i = 0; i < K; i++) dp[1 << i][i] = 1;

  for (int msk = 1; msk < 1 << K; msk++) {
    for (int last = 0; last < K; last++) {
      if ((msk >> last & 1) == 0) continue;
      for (int nxt = 0; nxt < K; nxt++) {
        if (msk >> nxt & 1) continue;

        dp[msk | (1 << nxt)][nxt] = min(dp[msk | (1 << nxt)][nxt], dp[msk][last] + Dist[last][nxt]);
      }
    }
  }

  int ans = INF;
  for (auto d : dp[(1 << K) - 1]) ans = min(ans, d);

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
