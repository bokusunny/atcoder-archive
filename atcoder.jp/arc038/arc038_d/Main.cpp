#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> X(2 * N);
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < N; i++) X[i + N] = X[i];
  Graph G(2 * N);
  vector<int> Deg(2 * N);  //向きを逆にしたグラフでの入次数(もとのグラフでの出次数)
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[B].push_back({A + N});
    G[B + N].push_back({A});
    Deg[A]++;
    Deg[A + N]++;
  }

  auto is_ok = [&](int x) {
    auto cdeg = Deg;
    vector<int> dp(2 * N, -1);
    queue<int> q;
    for (int i = 0; i < N; i++) {
      if (X[i] >= x) {
        dp[i] = 1;
        q.push(i);

        if (cdeg[i] == 0) {
          dp[i + N] = 0;
          q.push(i + N);
        }
      } else {
        dp[i + N] = 1;
        q.push(i + N);

        if (cdeg[i] == 0) {
          dp[i] = 0;
          q.push(i);
        }
      }
    }

    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto [to] : G[u]) {
        if (dp[to] != -1) continue;
        cdeg[to]--;
        if (dp[u] == 0) {
          dp[to] = 1;
          q.push(to);
        } else {
          if (cdeg[to] == 0) {
            dp[to] = 0;
            q.push(to);
          }
        }
      }
    }

    return dp[0] == 1;
  };

  int ok = -1, ng = 1 << 30;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;
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
