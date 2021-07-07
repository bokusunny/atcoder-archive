#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;

  Point operator-(const Point& other) { return Point{x - other.x, y - other.y}; }

  auto get_len() { return x * x + y * y; }
};

int main() {
  int N, K;
  cin >> N >> K;
  const long long INF = 1LL << 62;
  vector<Point> P(N);
  for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;

  vector<vector<long long>> dist(N, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = (P[i] - P[j]).get_len();
    }
  }

  vector<long long> cost(1 << N);
  for (int i = 0; i < 1 << N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        if (((i >> j) & 1) && ((i >> k) & 1)) cost[i] = max(cost[i], dist[j][k]);
      }
    }
  }

  vector<vector<long long>> dp(K + 1, vector<long long>(1 << N, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= K; i++) {
    for (int j = 1; j < (1 << N); j++) {
      for (int k = j; k != 0; k = (k - 1) & j) {
        dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], cost[k]));
      }
    }
  }

  cout << dp[K][(1 << N) - 1] << endl;

  return 0;
}
