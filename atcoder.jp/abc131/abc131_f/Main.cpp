#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N;
  cin >> N;
  const int V = 100100;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    X[i]--, Y[i]--;
  }

  Graph G(2 * V);
  for (int i = 0; i < N; i++) {
    G[X[i]].push_back(Y[i] + V);
    G[Y[i] + V].push_back(X[i]);
  }

  vector<bool> Seen(2 * V);
  auto dfs = [&](auto dfs, int u, int &cntx, int &cnty) -> void {
    if (Seen[u]) return;
    Seen[u] = true;
    if (u < V)
      cntx++;
    else
      cnty++;

    for (auto [v] : G[u]) {
      dfs(dfs, v, cntx, cnty);
    }
  };

  long long all = 0;
  for (int i = 0; i < 2 * V; i++) {
    if (Seen[i]) continue;
    int x = 0, y = 0;
    dfs(dfs, i, x, y);
    all += 1LL * x * y;
  }

  cout << all - N << endl;
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
