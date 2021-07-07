#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M);
  for (int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    X[i]--, Y[i]--;
  }

  vector<long long> dp(1 << N);
  dp[0] = 1;
  for (int i = 1; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        // jが最後に到達したとする
        bool is_ok = true;
        for (int k = 0; k < M; k++) {
          if (Y[k] != j) continue;
          if (i >> X[k] & 1) continue;
          is_ok = false;
          break;
        }
        if (is_ok) dp[i] += dp[i - (1 << j)];
      }
    }
  }

  cout << dp[(1 << N) - 1] << endl;

  return 0;
}
