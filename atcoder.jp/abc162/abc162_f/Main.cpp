#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  const long long INF = 1LL << 60;

  if (N & 1) {
    vector dp(N + 1, vector(2, vector<long long>(3, -INF)));
    dp[0][0][1] = 0;
    for (int i = 1; i <= N; i++) {
      if (i & 1) {
        // 選ばない
        dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][1]);
        dp[i][0][1] = max(dp[i][0][1], dp[i - 1][1][1]);
        // 選ぶ
        dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][0] + A[i - 1]);
        dp[i][1][2] = max(dp[i][1][2], dp[i - 1][0][1] + A[i - 1]);
      } else {
        // 選ばない
        dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][1]);
        dp[i][0][0] = max(dp[i][0][0], dp[i - 1][1][1]);
        dp[i][0][1] = max(dp[i][0][1], dp[i - 1][1][2]);
        // 選ぶ
        dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][1] + A[i - 1]);
      }
    }
    cout << max(dp[N][0][1], dp[N][1][1]) << endl;
  } else {
    vector dp(N + 1, vector<long long>(2, -INF));  // dp[i][is_last]
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
      if (i & 1) {
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + A[i - 1]);
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        dp[i][0] = max(dp[i][0], dp[i - 1][1]);
      } else {
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + A[i - 1]);
        dp[i][0] = max(dp[i][0], dp[i - 1][1]);
      }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
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
