#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  const int INF = 1 << 30;
  vector<int> dp(N + 1, INF);
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 1; i + j <= N; j *= 6) {
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
    for (int j = 9; i + j <= N; j *= 9) {
      dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
  }

  cout << dp.back() << endl;
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
