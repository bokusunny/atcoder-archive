#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<int, int, int>> J(N);
  for (int i = 0; i < N; i++) cin >> get<0>(J[i]) >> get<1>(J[i]) >> get<2>(J[i]);
  sort(J.begin(), J.end());

  vector<vector<long long>> dp(N + 1, vector<long long>(5010, -1));
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    auto [D, C, S] = J[i];
    for (int j = 0; j < 5010; j++) {
      if (dp[i][j] == -1) continue;

      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + C <= D) dp[i + 1][j + C] = max(dp[i + 1][j + C], dp[i][j] + S);
    }
  }

  long long ans = -1;
  for (auto v : dp[N]) ans = max(ans, v);

  cout << ans << endl;

  return 0;
}
