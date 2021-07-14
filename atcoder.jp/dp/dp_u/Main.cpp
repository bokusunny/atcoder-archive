#include <bits/stdc++.h>
using namespace std;

long long A[20][20];
const long long INF = 1LL << 62;
vector<long long> dp, sum;

long long rec(int bit) {
  if (__builtin_popcount(bit) <= 1) return 0;
  if (dp[bit] != -INF) return dp[bit];

  long long ret = 0;
  for (int mask = bit; mask != 0; mask = (mask - 1) & bit) {
    long long tmp = 0;
    tmp += sum[mask];
    tmp += rec(bit & ~mask);
    if (ret < tmp) ret = tmp;
  }

  return dp[bit] = ret;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  dp.assign(1 << N, -INF), sum.assign(1 << N, -INF);
  dp[0] = sum[0] = 0;
  for (int i = 0; i < N; i++) dp[1 << i] = sum[1 << i] = 0;

  for (int i = 1; i < 1 << N; i++) {
    assert(sum[i] != -INF);
    for (int j = 0; j < N; j++) {
      if (i >> j & 1 || sum[i | 1 << j] != -INF) continue;
      long long tmp = sum[i];
      for (int k = 0; k < N; k++) {
        if (i >> k & 1) tmp += A[j][k];
      }
      sum[i | 1 << j] = tmp;
    }
  }

  cout << rec((1 << N) - 1) << endl;

  return 0;
}
