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

long long A[400];
long long S[401];
vector<vector<long long>> dp;
const long long INF = 1LL << 62;

long long rec(int l, int r) {
  assert(r - l >= 0);
  if (r - l <= 1 || dp[l][r] != INF) return dp[l][r];

  chmin(dp[l][r], rec(l + 1, r - 1) + (S[r] - S[l]) + (S[r + 1] - S[l]));
  chmin(dp[l][r], rec(l + 1, r - 1) + (S[r + 1] - S[l + 1]) + (S[r + 1] - S[l]));
  for (int i = l; i <= r - 1; i++) {
    chmin(dp[l][r], rec(l, i) + rec(i + 1, r) + (S[r + 1] - S[l]));
  }

  return dp[l][r];
}

int main() {
  int N;
  cin >> N;
  dp.assign(N, vector<long long>(N, INF));
  for (int i = 0; i < N; i++) cin >> A[i], S[i + 1] = S[i] + A[i];
  for (int i = 0; i < N; i++) {
    dp[i][i] = 0;
    if (i != N - 1) dp[i][i + 1] = A[i] + A[i + 1];
  }

  cout << rec(0, N - 1) << endl;

  return 0;
}
