#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

  const int MX = 500;
  const int INF = 1 << 30;
  vector dp(N + 1, vector(MX + 1, vector<int>(MX + 1, INF)));
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int a = 0; a < MX; a++) {
      for (int b = 0; b < MX; b++) {
        if (dp[i][a][b] == INF) continue;
        dp[i + 1][a][b] = min(dp[i + 1][a][b], dp[i][a][b]);
        dp[i + 1][a + A[i]][b + B[i]] = min(dp[i + 1][a + A[i]][b + B[i]], dp[i][a][b] + C[i]);
      }
    }
  }

  int ans = INF;
  for (int a = 1; a < MX; a++) {
    for (int b = 1; b < MX; b++) {
      if (dp[N][a][b] == INF) continue;
      auto g = gcd(a, b);
      if (a / g != Ma || b / g != Mb) continue;
      ans = min(ans, dp[N][a][b]);
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
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
