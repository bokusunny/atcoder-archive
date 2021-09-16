#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  long long w;
};
using Graph = vector<vector<Edge>>;

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  auto warshall_floyd = [](const Graph &graph) {
    int n = (int)graph.size();
    const long long inf = 1LL << 60;
    vector Dist(n, vector<long long>(n, inf));
    for (int i = 0; i < n; i++) Dist[i][i] = 0;
    for (int from = 0; from < n; from++) {
      for (auto [to, w] : graph[from]) {
        Dist[from][to] = min(Dist[from][to], w);
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
        }
      }
    }

    return Dist;
  };

  auto dist = warshall_floyd(G);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      ans += dist[i][j];
    }
  }
  int K;
  cin >> K;
  while (K--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    if (dist[x][y] <= z) {
      cout << ans << endl;
    } else {
      ans -= dist[x][y] - z;
      dist[x][y] = dist[y][x] = z;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (dist[i][j] > dist[i][x] + dist[x][j]) {
            ans -= dist[i][j] - (dist[i][x] + dist[x][j]);
            dist[i][j] = dist[j][i] = dist[i][x] + dist[x][j];
          }
        }
      }
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (dist[i][j] > dist[i][y] + dist[y][j]) {
            ans -= dist[i][j] - (dist[i][y] + dist[y][j]);
            dist[i][j] = dist[j][i] = dist[i][y] + dist[y][j];
          }
        }
      }

      cout << ans << endl;
    }
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
