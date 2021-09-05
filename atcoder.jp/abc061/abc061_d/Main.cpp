#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to;
  long long w;
};
auto bellman_ford(const vector<Edge> &E, int V, int s) {
  const long long INF = 1LL << 62;
  vector<long long> D(V, INF);
  D[s] = 0;

  for (int i = 0; i < V; i++) {
    for (auto [from, to, w] : E) {
      if (D[from] == INF || D[from] + w >= D[to]) continue;
      D[to] = D[from] + w;
    }
  }

  long long ans = D[V - 1];

  vector<bool> Negative(V, false);
  for (int i = 0; i < V; i++) {
    for (auto [from, to, w] : E) {
      if (D[from] == INF || D[from] + w >= D[to]) continue;
      D[to] = D[from] + w;
      Negative[from] = true;
      Negative[to] = true;
    }
  }

  if (Negative[V - 1]) {
    cout << "inf" << endl;
    exit(0);
  }

  return ans;
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<Edge> E;
  for (int i = 0; i < M; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    a--, b--;
    E.push_back({a, b, -c});
  }

  auto ans = bellman_ford(E, N, 0);
  cout << -ans << endl;
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
