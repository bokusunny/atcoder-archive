#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> L(K), R(K);
  for (int i = 0; i < K; i++) cin >> L[i] >> R[i];
  vector<mint> dp(N);
  dp[0] = 1, dp[1] = -1;

  for (int i = 0; i < N; i++) {
    if (i != 0) dp[i] += dp[i - 1];
    for (int j = 0; j < K; j++) {
      if (i + L[j] < N) dp[i + L[j]] += dp[i];
      if (i + R[j] + 1 < N) dp[i + R[j] + 1] -= dp[i];
    }
  }

  cout << dp[N - 1].val() << endl;

  return 0;
}
