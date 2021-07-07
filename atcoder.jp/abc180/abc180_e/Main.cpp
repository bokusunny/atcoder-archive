#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N), Y(N), Z(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];

  vector<vector<long long>> Cost(N, vector<long long>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Cost[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0LL, Z[i] - Z[j]);
    }
  }

  const long long INF = 1LL << 62;
  vector<vector<long long>> dp(1 << N, vector<long long>(N, INF));
  dp[1][0] = 0;
  for (int i = 1; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if ((i >> j & 1) == 0) continue;

      for (int k = 0; k < N; k++) {
        if ((i >> k & 1) == 0 || k == j) continue;
        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + Cost[k][j]);
      }
    }
  }

  long long ans = INF;
  for (int i = 0; i < N; i++) {
    ans = min(ans, dp[(1 << N) - 1][i] + Cost[i][0]);
  }

  cout << ans << endl;

  return 0;
}
