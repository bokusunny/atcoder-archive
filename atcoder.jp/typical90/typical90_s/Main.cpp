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

// dp[l][r] := [l, r)を取り除く最小コスト
vector<vector<int>> dp;
int A[400];
const int INF = 1000000001;

int rec(int l, int r) {
  if (r - l == 2) {
    int val = abs(A[l] - A[r - 1]);
    dp[l][r] = val;
    return val;
  }

  if (dp[l][r] != INF) return dp[l][r];

  chmin(dp[l][r], rec(l + 1, r - 1) + abs(A[l] - A[r - 1]));
  for (int i = l + 1; i <= r - 1; i++) {
    if ((i - l) % 2 == 1 || (r - i) % 2 == 1) continue;
    chmin(dp[l][r], rec(l, i) + rec(i, r));
  }

  return dp[l][r];
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < 2 * N; i++) cin >> A[i];
  dp.assign(2 * N + 1, vector<int>(2 * N + 1, INF));

  cout << rec(0, 2 * N) << endl;

  return 0;
}
