#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  string S;
  cin >> S;
  int N = (int)S.size();

  // dp[i][j] := 上からi桁見た時、あまりがjであるものの個数
  vector<vector<mint>> dp(N + 1, vector<mint>(13));
  dp[N][0] = 1;
  int m = 1;  // 10^iを13で割ったあまり
  for (int i = N - 1; i >= 0; i--) {
    char c = S[i];
    for (int j = 0; j < 13; j++) {
      if (c == '?') {
        for (int k = 0; k < 10; k++) {
          auto new_j = (j + m * k) % 13;
          dp[i][new_j] += dp[i + 1][j];
        }
      } else {
        auto k = c - '0';
        auto new_j = (j + m * k) % 13;
        dp[i][new_j] += dp[i + 1][j];
      }
    }
    m *= 10;
    m %= 13;
  }

  cout << dp[0][5].val() << endl;

  return 0;
}
