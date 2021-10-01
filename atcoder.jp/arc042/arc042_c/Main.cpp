#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, P;
  cin >> N >> P;
  vector<pair<int, int>> S(N);
  for (int i = 0; i < N; i++) cin >> S[i].first >> S[i].second;
  sort(S.begin(), S.end(), greater<pair<int, int>>());

  vector dp(N + 1, vector<int>(P + 2));  // P+1は超えていることを意味
  for (int i = 0; i < N; i++) {
    auto [a, b] = S[i];
    for (int j = 0; j <= P + 1; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j <= P) {
        dp[i + 1][min(j + a, P + 1)] = max(dp[i + 1][min(j + a, P + 1)], dp[i][j] + b);
      }
    }
  }

  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
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
