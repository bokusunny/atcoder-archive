#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  int K;
  cin >> K;

  // dp[i][is_less][0_cnt]
  vector<vector<vector<long long>>> dp((int)N.size() + 1, vector<vector<long long>>(2, vector<long long>(K + 1)));
  dp[0][0][0] = 1;

  for (int i = 0; i < (int)N.size(); i++) {
    for (int j = 0; j < 2; j++) {
      int lim = j ? 9 : N[i] - '0';
      for (int k = 0; k <= K; k++) {
        for (int l = 0; l <= lim; l++) {
          if (k == K && l != 0) continue;
          dp[i + 1][j || l < lim][k + (l != 0)] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[(int)N.size()][0][K] + dp[(int)N.size()][1][K] << endl;

  return 0;
}
