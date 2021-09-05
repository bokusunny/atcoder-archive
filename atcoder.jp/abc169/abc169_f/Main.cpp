#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;
mint two = 2;

void solve() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector dp(N + 1, vector<mint>(S + 1));
  dp[0][0] = two.pow(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i + 1][j] += dp[i][j];
      if (j + A[i] <= S) dp[i + 1][j + A[i]] += dp[i][j] / 2;
    }
  }

  cout << dp[N][S].val() << endl;
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
