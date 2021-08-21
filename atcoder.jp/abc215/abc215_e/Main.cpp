#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

void solve() {
  int N;
  string S;
  cin >> N >> S;

  vector dp(N + 1, vector(1 << 10, vector<mint>(10)));
  for (int i = 0; i < N; i++) {
    int cur = S[i] - 'A';
    dp[i + 1][1 << cur][cur]++;
    for (int msk = 0; msk < 1 << 10; msk++) {
      for (int last = 0; last < 10; last++) {
        if (dp[i][msk][last] == 0) continue;
        dp[i + 1][msk][last] += dp[i][msk][last];

        if ((msk >> cur & 1) && (last != cur)) continue;
        dp[i + 1][msk | (1 << cur)][cur] += dp[i][msk][last];
      }
    }
  }

  mint ans = 0;
  for (int msk = 0; msk < 1 << 10; msk++) {
    for (int last = 0; last < 10; last++) {
      ans += dp[N][msk][last];
    }
  }

  cout << ans.val() << endl;
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
