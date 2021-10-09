#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

#include <atcoder/segtree>
using namespace atcoder;

using S = mint;
S op(S a, S b) { return a + b; }
S e() { return 0; }

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> B[i];

  segtree<S, op, e> seg(3001);
  vector<segtree<S, op, e>> dp(N + 1, seg);
  dp[0].set(0, 1);
  for (int i = 1; i <= N; i++) {
    for (int j = A[i - 1]; j <= B[i - 1]; j++) {
      dp[i].set(j, dp[i - 1].prod(0, j + 1));
    }
  }

  cout << dp[N].all_prod().val() << endl;
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
