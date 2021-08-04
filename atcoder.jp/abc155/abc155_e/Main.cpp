#include <bits/stdc++.h>
using namespace std;

string N;

void solve() {
  cin >> N;
  int sz = (int)N.size();

  // dp[i][is_kuriage] := 下からi行目まで、その行で繰り上げしたかどうかで分けた最適値
  const long long INF = 1LL << 62;
  vector<vector<long long>> dp(sz + 1, vector<long long>(2, INF));
  dp[sz][0] = 0;
  for (int i = sz; i >= 1; i--) {
    auto val = N[i - 1] - '0';
    // not is_kuriage
    dp[i - 1][1] = min(dp[i - 1][1], dp[i][0] + (10 - val));
    dp[i - 1][0] = min(dp[i - 1][0], dp[i][0] + val);
    // is_kuriage
    dp[i - 1][1] = min(dp[i - 1][1], dp[i][1] + (9 - val));
    dp[i - 1][0] = min(dp[i - 1][0], dp[i][1] + val + 1);
  }

  cout << min(dp[0][0], dp[0][1] + 1) << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
