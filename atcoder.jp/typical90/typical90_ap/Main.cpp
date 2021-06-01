#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin >> k;
  const long long MOD = 1000000007;

  if (k % 9 != 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<long long> dp(k + 1);
  dp.at(0) = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 1; j < 10; j++) {
      if (i + j <= k) {
        dp.at(i + j) += dp.at(i);
        dp.at(i + j) %= MOD;
      };
    }
  }

  cout << dp[k] << endl;

  return 0;
}
