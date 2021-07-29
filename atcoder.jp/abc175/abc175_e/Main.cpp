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

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  vector<vector<long long>> I(R, vector<long long>(C, -1));
  for (int i = 0; i < K; i++) {
    int r, c;
    long long v;
    cin >> r >> c >> v;
    r--, c--;
    I[r][c] = v;
  }

  vector<vector<vector<long long>>> dp(R, vector<vector<long long>>(C, vector<long long>(4)));
  if (I[0][0] != -1) dp[0][0][1] = I[0][0];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k <= 3; k++) {
        if (i < R - 1) {
          chmax(dp[i + 1][j][0], dp[i][j][k]);
          if (I[i + 1][j] != -1) {
            chmax(dp[i + 1][j][1], dp[i][j][k] + I[i + 1][j]);
          }
        }
        if (j < C - 1) {
          chmax(dp[i][j + 1][k], dp[i][j][k]);
          if (I[i][j + 1] && k < 3) {
            chmax(dp[i][j + 1][k + 1], dp[i][j][k] + I[i][j + 1]);
          }
        }
      }
    }
  }

  long long ans = 0;
  for (auto val : dp[R - 1][C - 1]) chmax(ans, val);
  cout << ans << endl;

  return 0;
}
