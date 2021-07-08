#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      A[i] |= (a << j);
    }
  }

  vector<mint> dp(1 << N);
  dp[0] = 1;

  for (int S = 0; S < 1 << N; S++) {
    int i = __builtin_popcount(S);  // 現時点でマッチングしているのはi人
    for (int j = 0; j < N; j++) {
      if ((S >> j & 1) == 0 || (A[i - 1] >> j & 1) == 0) continue;
      dp[S] += dp[S ^ (1 << j)];
    }
  }

  cout << dp[(1 << N) - 1].val() << endl;

  return 0;
}
