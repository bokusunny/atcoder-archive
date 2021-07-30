#include <bits/stdc++.h>
using namespace std;

int N, t, a;
using Graph = vector<vector<int>>;
Graph G;
vector<int> da, dt;

void bfs1(int s) {
  queue<int> q;
  q.push(s);
  da[s] = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (da[v] != -1) continue;
      da[v] = da[u] + 1;
      q.push(v);
    }
  }
}

void bfs2(int s) {
  queue<int> q;
  q.push(s);
  dt[s] = 0;
  int ans = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    if (dt[u] >= da[u]) continue;

    ans = max(ans, da[u] - 1);

    for (auto v : G[u]) {
      if (dt[v] != -1) continue;
      dt[v] = dt[u] + 1;
      q.push(v);
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> N >> t >> a;
  t--, a--;
  G.resize(N), da.assign(N, -1), dt.assign(N, -1);
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back(B);
    G[B].push_back(A);
  }
  bfs1(a);
  bfs2(t);

  return 0;
}
