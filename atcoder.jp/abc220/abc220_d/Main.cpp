#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector dp(N, vector<mint>(10));  // i回目の操作を終えて左端がjとなる回数
  dp[0][A[0]] = true;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][(j + A[i]) % 10] += dp[i - 1][j];
      dp[i][(j * A[i]) % 10] += dp[i - 1][j];
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << dp[N - 1][i].val() << endl;
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
