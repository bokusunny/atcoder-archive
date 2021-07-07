#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S = to_string(N);
  int K = (int)S.size();

  vector<vector<vector<long long>>> dp(K + 1, vector<vector<long long>>(2, vector<long long>(K + 1)));
  dp[0][0][0] = 1;

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < 2; j++) {
      int lim = j ? 9 : S[i] - '0';

      for (int k = 0; k <= K; k++) {
        for (int l = 0; l <= lim; l++) {
          dp[i + 1][j || l < lim][k + (l == 1)] += dp[i][j][k];
        }
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < 2; i++) {
    for (long long j = 1; j <= K; j++) {
      ans += j * dp[K][i][j];
    }
  }

  cout << ans << endl;

  return 0;
}
