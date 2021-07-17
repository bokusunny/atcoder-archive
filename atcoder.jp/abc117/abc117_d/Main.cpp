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
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // dp[i][is_less] := 下からi番目まで見た時の最適解(上から降っていく)
  const long long INF = 1LL << 62;
  vector<vector<long long>> dp(46, vector<long long>(2, -INF));
  dp[45][0] = 0;
  for (int i = 44; i >= 0; i--) {
    int zero_cnt = 0, one_cnt = 0;
    for (auto a : A) {
      if (a >> i & 1)
        one_cnt++;
      else
        zero_cnt++;
    }

    if (dp[i + 1][1] >= 0) {
      chmax(dp[i][1], dp[i + 1][1] + (1LL << i) * max(one_cnt, zero_cnt));
    }
    if (dp[i + 1][0] >= 0) {
      if (K >> i & 1) {
        chmax(dp[i][1], dp[i + 1][0] + (1LL << i) * one_cnt);
        chmax(dp[i][0], dp[i + 1][0] + (1LL << i) * zero_cnt);
      } else {
        chmax(dp[i][0], dp[i + 1][0] + (1LL << i) * one_cnt);
      }
    }
  }

  cout << max(dp[0][0], dp[0][1]) << endl;

  return 0;
}
