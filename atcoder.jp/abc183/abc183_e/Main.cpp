#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<mint>> dp(H, vector<mint>(W));
  vector<vector<mint>> X(H, vector<mint>(W)), Y(H, vector<mint>(W)), Z(H, vector<mint>(W));
  dp[0][0] = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#' || (i == 0 && j == 0)) continue;
      if (i != 0 && grid[i - 1][j] != '#') Y[i][j] = Y[i - 1][j] + dp[i - 1][j];
      if (j != 0 && grid[i][j - 1] != '#') X[i][j] = X[i][j - 1] + dp[i][j - 1];
      if (i != 0 && j != 0 && grid[i][j] != '#') Z[i][j] = Z[i - 1][j - 1] + dp[i - 1][j - 1];

      dp[i][j] = X[i][j] + Y[i][j] + Z[i][j];
    }
  }

  cout << dp[H - 1][W - 1].val() << endl;

  return 0;
}
