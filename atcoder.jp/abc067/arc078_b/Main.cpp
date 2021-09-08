#include <bits/stdc++.h>
using namespace std;

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

  vector<int> Col(N, -1);
  Col[0] = 1;
  Col[N - 1] = 0;
  queue<pair<int, int>> q;
  q.emplace(1, 0);
  q.emplace(0, N - 1);

  while (!q.empty()) {
    auto [col, u] = q.front();
    q.pop();
    for (auto [v] : G[u]) {
      if (Col[v] != -1) continue;
      Col[v] = col;
      q.emplace(col, v);
    }
  }

  int fcnt = accumulate(Col.begin(), Col.end(), 0);
  int scnt = N - fcnt;

  if (fcnt > scnt) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
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
