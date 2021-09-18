#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  int X, Y;
  cin >> X >> Y;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  vector dp(N + 1, vector(X + 1, vector<int>(Y + 1, 500)));
  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int x = 0; x <= X; x++) {
      for (int y = 0; y <= Y; y++) {
        if (dp[i][x][y] == 500) continue;
        dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y]);
        dp[i + 1][min(X, x + A[i])][min(Y, y + B[i])] =
            min(dp[i + 1][min(X, x + A[i])][min(Y, y + B[i])], dp[i][x][y] + 1);
      }
    }
  }

  if (dp[N][X][Y] == 500) {
    cout << -1 << endl;
  } else {
    cout << dp[N][X][Y] << endl;
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
