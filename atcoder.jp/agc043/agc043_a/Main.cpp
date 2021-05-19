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

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      grid[i][j] = c;
    }
  }

  const long long INF = 1LL << 60;
  vector<vector<long long>> dp(h, vector<long long>(w, INF));
  grid[0][0] == '#' ? dp[0][0] = 1 : dp[0][0] = 0;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      // 右に配る
      if (j != w - 1) {
        if (grid[i][j + 1] == '.') {
          chmin(dp[i][j + 1], dp[i][j]);
        } else if (grid[i][j + 1] == '#') {
          if (grid[i][j] == '.') {
            chmin(dp[i][j + 1], dp[i][j] + 1);
          } else if (grid[i][j] == '#') {
            chmin(dp[i][j + 1], dp[i][j]);
          }
        }
      }
      // 下に配る
      if (i != h - 1) {
        if (grid[i + 1][j] == '.') {
          chmin(dp[i + 1][j], dp[i][j]);
        } else if (grid[i + 1][j] == '#') {
          if (grid[i][j] == '.') {
            chmin(dp[i + 1][j], dp[i][j] + 1);
          } else if (grid[i][j] == '#') {
            chmin(dp[i + 1][j], dp[i][j]);
          }
        }
      }
    }
  }

  cout << dp[h - 1][w - 1] << endl;

  return 0;
}
