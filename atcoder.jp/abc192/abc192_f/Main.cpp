#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  long long X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  const long long INF = 1LL << 60;
  long long ans = INF;
  for (int k = 1; k <= N; k++) {
    vector dp(N + 1, vector(N + 1, vector<long long>(k, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= min(i, k); j++) {
        for (int mo = 0; mo < k; mo++) {
          if (dp[i][j][mo] == -1) continue;

          long long nxt_mo = (dp[i][j][mo] + A[i]) % k;
          dp[i + 1][j][mo] = max(dp[i + 1][j][mo], dp[i][j][mo]);
          dp[i + 1][j + 1][nxt_mo] = max(dp[i + 1][j + 1][nxt_mo], dp[i][j][mo] + A[i]);
        }
      }
    }
    if (dp[N][k][X % k] == -1) continue;
    ans = min(ans, (X - dp[N][k][X % k]) / k);
  }

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
