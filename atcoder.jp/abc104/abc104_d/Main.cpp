#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  string S;
  cin >> S;
  int sz = (int)S.size();

  vector dp(sz + 1, vector<mint>(4));
  dp[0][0] = 1;
  for (int i = 0; i < sz; i++) {
    if (S[i] == '?') {
      for (int j = 0; j < 4; j++) {
        dp[i + 1][j] += dp[i][j] * 3;
      }
      for (int j = 1; j < 4; j++) {
        dp[i + 1][j] += dp[i][j - 1];
      }
    } else {
      for (int j = 0; j < 4; j++) {
        dp[i + 1][j] += dp[i][j];
      }
      dp[i + 1][S[i] - 'A' + 1] += dp[i + 1][S[i] - 'A'];
    }
  }

  cout << dp[sz][3].val() << endl;
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
