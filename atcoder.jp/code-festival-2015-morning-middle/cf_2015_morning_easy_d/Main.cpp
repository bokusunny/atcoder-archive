#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  string S;
  cin >> N >> S;

  int ans = N;
  for (int i = 0; i <= N; i++) {
    string s1 = S.substr(0, i);
    string s2 = S.substr(i);
    int sz1 = (int)s1.size();
    int sz2 = (int)s2.size();

    vector dp(sz1 + 1, vector<int>(sz2 + 1));
    for (int i = 0; i <= sz1; i++) {
      for (int j = 0; j <= sz2; j++) {
        if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1]));
      }
    }
    ans = min(ans, N - 2 * dp[sz1][sz2]);
  }

  cout << ans << endl;
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
