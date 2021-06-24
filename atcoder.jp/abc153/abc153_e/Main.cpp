#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int H, N;
  cin >> H >> N;

  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  const long long INF = 1LL << 60;
  vector<vector<long long>> dp(N + 1, vector<long long>(H + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= H; j++) {
      chmin(dp[i + 1][j], dp[i][j]);
      chmin(dp[i + 1][min((long long)H, j + A[i])], dp[i + 1][j] + B[i]);
    }
  }

  cout << dp[N][H] << endl;

  return 0;
}
