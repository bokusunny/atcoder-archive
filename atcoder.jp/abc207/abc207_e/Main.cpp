#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> S(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    S[i + 1] = S[i] + A[i];
  }

  // X[i][j] := mod jの世界で、i未満でS[i] ≡ S[x] になる最大のx
  vector<vector<int>> X(N + 1, vector<int>(N + 1));
  // pre[i][j] := mod jの世界で、直前にiだったx
  vector<vector<int>> pre(N + 1, vector<int>(N + 1));

  for (int i = 0; i < N + 1; i++) {
    // S[i]についてj(1~N)のmodをとる
    for (int j = 1; j < N + 1; j++) {
      auto amari = S[i] % j;
      X[i][j] = pre[amari][j];
      pre[amari][j] = i;
    }
  }

  vector<vector<mint>> dp(N + 1, vector<mint>(N + 1));
  dp[0][0] = 1;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      dp[i][j] = dp[X[i][j]][j] + dp[X[i][j]][j - 1];
    }
  }

  mint ans = 0;
  for (auto v : dp[N]) ans += v;

  cout << ans.val() << endl;

  return 0;
}
