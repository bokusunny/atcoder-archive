#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<mint>> dp(N + 1, vector<mint>(9));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 9; j++) {
      dp[i + 1][j] += dp[i][j];
    }
    if (S[i] == 'c') {
      dp[i + 1][1] += dp[i][0];
    } else if (S[i] == 'h') {
      dp[i + 1][2] += dp[i][1];
    } else if (S[i] == 'o') {
      dp[i + 1][3] += dp[i][2];
    } else if (S[i] == 'k') {
      dp[i + 1][4] += dp[i][3];
    } else if (S[i] == 'u') {
      dp[i + 1][5] += dp[i][4];
    } else if (S[i] == 'd') {
      dp[i + 1][6] += dp[i][5];
    } else if (S[i] == 'a') {
      dp[i + 1][7] += dp[i][6];
    } else if (S[i] == 'i') {
      dp[i + 1][8] += dp[i][7];
    }
  }

  cout << dp[N][8].val() << endl;

  return 0;
}
