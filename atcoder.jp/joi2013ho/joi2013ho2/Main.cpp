#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N), T(M);
  for (int i = 0; i < N; i++) {
    char c;
    cin >> c;
    if (c == 'I')
      S[i] = 1;
    else
      S[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    char c;
    cin >> c;
    if (c == 'I')
      T[i] = 1;
    else
      T[i] = 0;
  }

  const int INF = 1 << 30;
  vector dp(N + 1, vector(M + 1, vector<int>(2)));  // dp[i][j][last], lastは0: 'O', 1; 'I'
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j][0] = 0;
      dp[i][j][1] = -INF;
    }
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i > 0) dp[i][j][S[i - 1]] = max(dp[i][j][S[i - 1]], dp[i - 1][j][!S[i - 1]] + 1);
      if (j > 0) dp[i][j][T[j - 1]] = max(dp[i][j][T[j - 1]], dp[i][j - 1][!T[j - 1]] + 1);
    }
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      ans = max(ans, dp[i][j][1]);
    }
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
