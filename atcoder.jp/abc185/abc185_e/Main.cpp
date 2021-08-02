#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int N, M;
vector<int> A, B;

void solve() {
  cin >> N >> M;
  A.resize(N), B.resize(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  const int INF = 1 << 30;
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);
      if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
      if (i > 0 && j > 0) chmin(dp[i][j], dp[i - 1][j - 1] + (A[i - 1] != B[j - 1]));
    }
  }

  cout << dp[N][M] << endl;
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
