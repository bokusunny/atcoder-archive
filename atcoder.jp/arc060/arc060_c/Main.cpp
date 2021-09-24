#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  int L;
  cin >> L;
  const int logK = 31;
  vector dp(N, vector<int>(logK, -1));  // dp[i][k] := iから2^k日移動した時の最高到達先
  for (int i = 0; i < N; i++) {
    auto itr = upper_bound(X.begin(), X.end(), X[i] + L);
    dp[i][0] = itr - X.begin() - 1;
  }
  for (int k = 0; k < logK - 1; k++) {
    for (int i = 0; i < N; i++) {
      dp[i][k + 1] = dp[dp[i][k]][k];
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);

    int now = a;
    int ans = 0;
    while (now < b) {
      auto itr = lower_bound(dp[now].begin(), dp[now].end(), b);
      auto k = itr - dp[now].begin();
      if (k != 0) {
        itr--;
        k--;
      }
      ans += 1 << k;
      now = *itr;
    }
    cout << ans << endl;
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
