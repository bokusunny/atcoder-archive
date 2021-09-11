#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to;
  long long w;
};
auto bellman_ford(const vector<Edge> &E, int N, int s, int g) {
  const long long INF = 1LL << 60;
  vector<long long> Dist(N, INF);
  Dist[s] = 0;
  for (int i = 0; i < N; i++) {
    for (auto [from, to, w] : E) {
      long long nd = Dist[from] + w;
      if (Dist[from] == INF || Dist[to] <= nd) continue;

      Dist[to] = nd;
    }
  }

  long long res = Dist[g];

  vector<bool> Negative(N);  // Negative[i] := iが負閉路に含まれるか
  for (int i = 0; i < N; i++) {
    for (auto [from, to, w] : E) {
      if (Negative[from]) Negative[to] = true;
      long long nd = Dist[from] + w;
      if (Dist[from] == INF || Dist[to] <= nd) continue;
      Dist[to] = nd;
      Negative[from] = Negative[to] = true;
    }
  }

  if (Negative[g]) {
    cout << -1 << endl;
    exit(0);
  }

  return res;
}

void solve() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<Edge> E(M);
  for (int i = 0; i < M; i++) {
    cin >> E[i].from >> E[i].to >> E[i].w;
    E[i].from--, E[i].to--;
    E[i].w -= P;
    E[i].w *= -1;
  }

  auto ans = bellman_ford(E, N, 0, N - 1);
  cout << max(-ans, 0LL) << endl;
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
