#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, pair<int, int>> Zahyo;
  for (int i = 0; i < N; i++) {
    int X, C;
    cin >> X >> C;
    if (Zahyo.count(C)) {
      Zahyo[C].first = min(Zahyo[C].first, X);
      Zahyo[C].second = max(Zahyo[C].second, X);
    } else {
      Zahyo[C] = {X, X};
    }
  }

  const long long INF = 1LL << 62;
  vector<vector<long long>> dp(N + 1, vector<long long>(2, INF));
  dp[0][0] = dp[0][1] = 0;

  int prev_mi = 0, prev_mx = 0;
  for (int i = 1; i <= N; i++) {
    if (!Zahyo.count(i)) {
      dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1];
      continue;
    }

    auto [mi, mx] = Zahyo[i];
    auto dist = mx - mi;
    dp[i][0] = min(dp[i - 1][0] + abs(prev_mi - mx), dp[i - 1][1] + abs(prev_mx - mx)) + dist;
    dp[i][1] = min(dp[i - 1][0] + abs(prev_mi - mi), dp[i - 1][1] + abs(prev_mx - mi)) + dist;
    prev_mi = mi, prev_mx = mx;
  }

  auto ans = min(dp[N][0] + abs(prev_mi), dp[N][1] + abs(prev_mx));
  cout << ans << endl;

  return 0;
}
