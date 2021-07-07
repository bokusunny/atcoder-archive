#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
  string S = to_string(x);

  vector<vector<vector<long long>>> dp((int)S.size() + 1, vector<vector<long long>>(2, vector<long long>(2)));
  dp[0][0][0] = 1;

  for (int i = 0; i < (int)S.size(); i++) {
    for (int is_less = 0; is_less < 2; is_less++) {
      auto lim = is_less ? 9 : S[i] - '0';
      for (int is_ng = 0; is_ng < 2; is_ng++) {
        for (int l = 0; l <= lim; l++) {
          dp[i + 1][is_less || l < lim][is_ng || (l == 4 || l == 9)] += dp[i][is_less][is_ng];
        }
      }
    }
  }

  return dp[(int)S.size()][0][1] + dp[(int)S.size()][1][1];
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << f(B) - f(A - 1) << endl;

  return 0;
}
