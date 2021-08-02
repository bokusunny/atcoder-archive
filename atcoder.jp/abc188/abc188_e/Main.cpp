#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int N, M;
vector<long long> A;
using Graph = vector<vector<int>>;
Graph G;
const long long INF = 1LL << 62;
vector<long long> cost, rieki;  // その町まで最適に行動した時の最小コスト、最大利益

long long rec(int u) {
  if (cost[u] != INF) return cost[u];
  cost[u] = A[u];
  for (auto v : G[u]) {
    chmin(cost[u], rec(v));
  }
  return cost[u];
}

long long rec2(int u) {
  if (rieki[u] != -INF) return rieki[u];
  for (auto v : G[u]) {
    chmax(rieki[u], rec2(v));
    chmax(rieki[u], A[u] - cost[v]);
  }
  return rieki[u];
}

void solve() {
  cin >> N >> M;
  G.resize(N), A.resize(N), cost.assign(N, INF), rieki.assign(N, -INF);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    X--, Y--;
    G[Y].push_back(X);
  }

  for (int i = 0; i < N; i++) {
    if (cost[i] != INF) continue;
    rec(i);
  }
  for (int i = 0; i < N; i++) {
    if (rieki[i] != -INF) continue;
    rec2(i);
  }
  long long ans = -INF;
  for (auto val : rieki) chmax(ans, val);
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
