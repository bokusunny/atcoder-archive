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

int H, W;
long long C;

long long solve(vector<vector<long long>> grid) {
  const long long INF = 1LL << 62;
  vector<vector<long long>> dp(H, vector<long long>(W, INF));

  long long res = INF;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i > 0) chmin(dp[i][j], dp[i - 1][j] + C);
      if (j > 0) chmin(dp[i][j], dp[i][j - 1] + C);
      chmin(res, dp[i][j] + grid[i][j]);
      chmin(dp[i][j], grid[i][j]);
    }
  }

  return res;
}

int main() {
  cin >> H >> W >> C;
  vector<vector<long long>> grid1(H, vector<long long>(W));
  vector<vector<long long>> grid2(H, vector<long long>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid1[i][j];
      grid2[i][W - 1 - j] = grid1[i][j];
    }
  }

  cout << min(solve(grid1), solve(grid2)) << endl;

  return 0;
}
