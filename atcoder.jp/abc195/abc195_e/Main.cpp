#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  string S, X;
  cin >> N >> S >> X;

  vector<vector<int>> dp(N + 1, vector<int>(7));
  dp[N][0] = 1;
  for (int i = N; i >= 1; i--) {
    auto val = S[i - 1] - '0';
    for (int j = 0; j < 7; j++) {
      if (X[i - 1] == 'T') {
        dp[i - 1][j] = dp[i][10 * j % 7] || dp[i][(10 * j + val) % 7];
      } else {
        dp[i - 1][j] = dp[i][10 * j % 7] && dp[i][(10 * j + val) % 7];
      }
    }
  }

  if (dp[0][0]) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
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
