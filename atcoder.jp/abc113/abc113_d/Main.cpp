#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int H, W, K;
  cin >> H >> W >> K;
  K--;

  vector dp(H + 1, vector<mint>(W));
  dp[0][0] = 1;
  for (int i = 0; i < H; i++) {
    for (int msk = 0; msk < 1 << (W - 1); msk++) {
      bool is_ok = true;
      for (int j = 1; j < (W - 1); j++) {
        if ((msk >> j & 1) && (msk >> (j - 1) & 1)) {
          is_ok = false;
          break;
        }
      }
      if (!is_ok) continue;

      for (int j = 0; j < W; j++) {
        if (j == 0) {
          if (msk >> j & 1) {
            dp[i + 1][j] += dp[i][j + 1];
          } else {
            dp[i + 1][j] += dp[i][j];
          }
        } else if (j == W - 1) {
          if (msk >> (j - 1) & 1) {
            dp[i + 1][j] += dp[i][j - 1];
          } else {
            dp[i + 1][j] += dp[i][j];
          }
        } else {
          if (msk >> (j - 1) & 1) {
            dp[i + 1][j] += dp[i][j - 1];
          } else if (msk >> (j)&1) {
            dp[i + 1][j] += dp[i][j + 1];
          } else {
            dp[i + 1][j] += dp[i][j];
          }
        }
      }
    }
  }

  cout << dp.back()[K].val() << endl;
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
