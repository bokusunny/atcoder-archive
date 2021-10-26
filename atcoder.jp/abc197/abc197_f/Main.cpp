#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector G(N, vector<vector<int>>(26));
  vector<set<int>> Adj(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    char C;
    cin >> C;
    G[A][C - 'a'].push_back(B);
    G[B][C - 'a'].push_back(A);
    Adj[A].insert(B);
    Adj[B].insert(A);
  }

  queue<pair<int, int>> q;
  const int INF = 1 << 30;
  vector Dist(N, vector<int>(N, INF));
  Dist[0][N - 1] = 0;
  q.emplace(0, N - 1);

  while (!q.empty()) {
    auto [a, b] = q.front();
    q.pop();

    if (Adj[a].count(b)) {
      cout << Dist[a][b] + 1 << endl;
      return;
    }

    for (int c = 0; c < 26; c++) {
      if (G[a][c].empty() || G[b][c].empty()) continue;

      for (auto aa : G[a][c]) {
        for (auto bb : G[b][c]) {
          if (Dist[aa][bb] != INF) continue;
          Dist[aa][bb] = Dist[a][b] + 2;
          if (aa == bb) {
            cout << Dist[aa][bb] << endl;
            return;
          }
          q.emplace(aa, bb);
        }
      }
    }
  }

  cout << -1 << endl;
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
