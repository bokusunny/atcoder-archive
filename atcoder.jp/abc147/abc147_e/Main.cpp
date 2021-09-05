#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W;
  cin >> H >> W;
  vector A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  vector B(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B[i][j];
    }
  }
  vector Diff(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      Diff[i][j] = abs(A[i][j] - B[i][j]);
    }
  }

  vector dp(H, vector<bitset<30000>>(W));
  const int base = 15000;
  dp[0][0].set(base + Diff[0][0]);
  dp[0][0].set(base - Diff[0][0]);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i + 1 < H) {
        dp[i + 1][j] |= (dp[i][j] << Diff[i + 1][j]);
        dp[i + 1][j] |= (dp[i][j] >> Diff[i + 1][j]);
      }
      if (j + 1 < W) {
        dp[i][j + 1] |= (dp[i][j] << Diff[i][j + 1]);
        dp[i][j + 1] |= (dp[i][j] >> Diff[i][j + 1]);
      }
    }
  }

  int ans = 15000;
  for (int i = 0; i < 30000; i++) {
    if (!dp[H - 1][W - 1][i]) continue;
    ans = min(ans, abs(i - base));
  }

  cout << ans << endl;
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
