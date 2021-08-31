#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

void solve() {
  int N;
  cin >> N;
  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; i++) cin >> AB[i].first;
  for (int i = 0; i < N; i++) cin >> AB[i].second;
  sort(AB.begin(), AB.end());

  vector dp(N + 1, vector<mint>(5001));  // i番目までの部分集合Sのうち、合計がjになるものの数
  dp[0][0] = 1;
  mint ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 5000; j++) {
      if (j + AB[i].second <= 5000) dp[i + 1][j + AB[i].second] += dp[i][j];
    }
    for (int j = 1; j <= AB[i].first; j++) ans += dp[i + 1][j];
    for (int j = 0; j <= 5000; j++) dp[i + 1][j] += dp[i][j];
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
