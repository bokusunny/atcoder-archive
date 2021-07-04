#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  const long long INF = 1LL << 60;
  vector<vector<long long>> dist(N, vector<long long>(N, INF));
  for (int i = 0; i < N; i++) dist[i][i] = 0;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    long long C;
    cin >> C;
    dist[A][B] = C;
  }

  long long ans = 0;
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] == INF || dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][j] != INF) ans += dist[i][j];
      }
    }
  }

  cout << ans << endl;

  return 0;
}
