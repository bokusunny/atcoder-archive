#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  const int INF = 1 << 30;
  vector dp(N + 1, vector<int>(5, INF));  // 前からi番目の耳まで見て既にj個通り過ぎている時の最適値
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 4; j++) {
      for (int k = j; k <= 4; k++) {
        if (k == 0 || k == 4) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + A[i]);
        } else if (k == 1 || k == 3) {
          if (A[i] == 0) {
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + 2);
          } else {
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + (A[i] % 2 == 1));
          }
        } else {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + (A[i] % 2 == 0));
        }
      }
    }
  }

  cout << *min_element(dp[N].begin(), dp[N].end()) << endl;
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
