#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int dig_cnt = (int)s.size();
  int d;
  cin >> d;
  const long long MOD = 1e9 + 7;

  vector<vector<vector<long long>>> dp(dig_cnt + 1, vector<vector<long long>>(2, vector<long long>(d, 0LL)));
  dp.at(0).at(0).at(0) = 1;  // 最後に1を引く

  for (int i = 0; i < dig_cnt; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < d; k++) {
        int lim = j ? 9 : s.at(i) - '0';
        for (int l = 0; l <= lim; l++) {
          dp.at(i + 1).at(j || l < lim).at((k + l) % d) += dp.at(i).at(j).at(k);
          dp.at(i + 1).at(j || l < lim).at((k + l) % d) %= MOD;
        }
      }
    }
  }

  long long ans = (dp.at(dig_cnt).at(0).at(0) + dp.at(dig_cnt).at(1).at(0) - 1 + MOD) % MOD;
  cout << ans << endl;

  return 0;
}
