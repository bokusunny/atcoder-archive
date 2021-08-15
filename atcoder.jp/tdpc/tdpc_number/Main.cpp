#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int D;
  string N;
  cin >> D >> N;
  int sz = (int)N.size();

  vector dp(sz + 1, vector(D, vector<mint>(2)));  // dp[i][mo][is_less]
  dp[0][0][0] = 1;
  for (int i = 0; i < sz; i++) {
    for (int is_less = 0; is_less < 2; is_less++) {
      auto lim = is_less ? 9 : N[i] - '0';
      for (int mo = 0; mo < D; mo++) {
        for (int j = 0; j <= lim; j++) {
          dp[i + 1][(mo + j) % D][is_less | (j < lim)] += dp[i][mo][is_less];
        }
      }
    }
  }

  cout << (dp.back()[0][0] + dp.back()[0][1]).val() - 1 << endl;
}

int main() {
  solve();

  return 0;
}
