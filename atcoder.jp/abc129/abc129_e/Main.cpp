#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  string L;
  cin >> L;
  int sz = (int)L.size();

  vector<vector<mint>> dp(sz + 1, vector<mint>(2));
  dp[0][0] = 1;
  for (int i = 1; i <= sz; i++) {
    if (L[i - 1] == '1') {
      dp[i][0] += 2 * dp[i - 1][0];
      dp[i][1] += dp[i - 1][0];
    } else {
      dp[i][0] += dp[i - 1][0];
    }
    dp[i][1] += 3 * dp[i - 1][1];
  }

  cout << (dp[sz][0] + dp[sz][1]).val() << endl;

  return 0;
}
