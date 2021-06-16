#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int n;
  cin >> n;

  vector<long long> A(n);
  for (auto &a : A) cin >> a;

  // dp[i][0]: +と-を並べて最後が+の場合の和
  vector<vector<mint>> dp(n, vector<mint>(2, 0));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < n - 1; i++) {
    dp.at(i + 1).at(0) = dp.at(i).at(0) + dp.at(i).at(1);
    dp.at(i + 1).at(1) = dp.at(i).at(0);
  }

  mint ans = 0;
  for (int i = 0; i < n; i++) {
    ans += A.at(i) * dp.at(i).at(0) * (dp.at(n - i - 1).at(0) + dp.at(n - i - 1).at(1));
    if (n - i - 1 == 0) {
      ans -= A.at(i) * dp.at(i).at(1);
    } else {
      ans -= A.at(i) * dp.at(i).at(1) * (dp.at(n - i - 2).at(0) + dp.at(n - i - 2).at(1));
    }
  }

  cout << ans.val() << endl;

  return 0;
}
