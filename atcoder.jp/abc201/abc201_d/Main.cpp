#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
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

  // dp[i][j]:
  //   (i+j)が奇数の時:
  //     青木くんスタートでgrid[i][j]からそれぞれが最適戦略を取った時の、grid[i][j]での高橋くんの得点-青木くんの得点の最小値
  //   (i+j)が偶数の時:
  //     高橋くんスタートでgrid[i][j]からそれぞれが最適戦略を取った時の、grid[i][j]での高橋くんの得点-青木くんの得点の最大値
  vector<vector<long long>> dp(h, vector<long long>(w, 0));
  const long long INF = 1LL << 60;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      (i + j) % 2 ? dp[i][j] = INF : dp[i][j] = -INF;
    }
  }
  dp[h - 1][w - 1] = 0;

  for (int i = h - 1; i >= 0; i--) {
    for (int j = w - 1; j >= 0; j--) {
      if ((i + j) % 2) {
        if (i != h - 1) {
          if (grid[i + 1][j] == '+') {
            chmin(dp[i][j], dp[i + 1][j] - 1);
          } else {
            chmin(dp[i][j], dp[i + 1][j] + 1);
          }
        }
        if (j != w - 1) {
          if (grid[i][j + 1] == '+') {
            chmin(dp[i][j], dp[i][j + 1] - 1);
          } else {
            chmin(dp[i][j], dp[i][j + 1] + 1);
          }
        }
      } else {
        if (i != h - 1) {
          if (grid[i + 1][j] == '+') {
            chmax(dp[i][j], dp[i + 1][j] + 1);
          } else {
            chmax(dp[i][j], dp[i + 1][j] - 1);
          }
        }
        if (j != w - 1) {
          if (grid[i][j + 1] == '+') {
            chmax(dp[i][j], dp[i][j + 1] + 1);
          } else {
            chmax(dp[i][j], dp[i][j + 1] - 1);
          }
        }
      }
    }
  }

  string ans;
  if (dp[0][0] == 0) {
    ans = "Draw";
  } else if (dp[0][0] > 0) {
    ans = "Takahashi";
  } else {
    ans = "Aoki";
  }

  cout << ans << endl;

  return 0;
}
