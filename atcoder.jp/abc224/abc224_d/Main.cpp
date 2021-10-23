#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

void solve() {
  int M;
  cin >> M;
  Graph G(9);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<int> P(8);
  for (int i = 0; i < 8; i++) cin >> P[i], P[i]--;
  vector<int> Koma(9, -1);
  for (int i = 0; i < 8; i++) {
    Koma[P[i]] = i;
  }
  int emp = find(Koma.begin(), Koma.end(), -1) - Koma.begin();

  map<vector<int>, int> Dist;
  queue<pair<vector<int>, int>> q;
  q.emplace(Koma, emp);
  Dist[Koma] = 0;

  while (!q.empty()) {
    auto [vec, emp] = q.front();
    q.pop();
    for (auto [to] : G[emp]) {
      auto vec_ = vec;
      vec_[emp] = vec[to];
      vec_[to] = -1;
      if (Dist.count(vec_)) continue;
      Dist[vec_] = Dist[vec] + 1;
      q.push({vec_, to});
    }
  }

  vector<int> ans(9, -1);
  for (int i = 0; i < 8; i++) ans[i] = i;

  if (Dist.count(ans)) {
    cout << Dist[ans] << endl;
  } else {
    cout << -1 << endl;
  }
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
