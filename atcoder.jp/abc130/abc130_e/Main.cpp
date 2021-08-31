#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  vector<int> T(M);
  for (int i = 0; i < M; i++) cin >> T[i];

  vector dp(N + 1, vector<mint>(M + 1));
  dp[0][0] = 1;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i > 0 && j > 0 && S[i - 1] == T[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1];
      }
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
      if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
    }
  }

  cout << dp[N][M].val() << endl;
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
