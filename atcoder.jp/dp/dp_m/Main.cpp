#include <bits/stdc++.h>
using namespace std;

int mod_min(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  long long n, k;
  cin >> n >> k;
  const long long MOD = 1e9 + 7;
  vector<long long> A(n);
  for (auto &a : A) cin >> a;

  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
  dp.at(0).at(0) = 1;

  for (int i = 1; i <= n; i++) {
    vector<long long> s(k + 2, 0);
    for (int j = 0; j <= k; j++) {
      s.at(j + 1) = s.at(j) + dp.at(i - 1).at(j);
      s.at(j + 1) %= MOD;
    }
    for (long long j = 0; j <= k; j++) {
      dp.at(i).at(j) = mod_min(s.at(j + 1) - s.at(max(0LL, j - A.at(i - 1))), MOD);
    }
  }

  cout << dp.at(n).at(k) << endl;

  return 0;
}
