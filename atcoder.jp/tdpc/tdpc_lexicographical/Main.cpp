#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  long long K;
  cin >> S >> K;
  int N = (int)S.size();
  const long long INF = 1LL << 60;

  vector dp(N + 1, vector<long long>(26));
  for (int i = N - 1; i >= 0; i--) {
    for (int c = 0; c < 26; c++) {
      if (c != (int)(S[i] - 'a')) {
        dp[i][c] = min(dp[i][c] + dp[i + 1][c], INF);
      } else {
        dp[i][c] = min(dp[i][c] + 1, INF);
        for (int c2 = 0; c2 < 26; c2++) {
          dp[i][c] = min(dp[i][c] + dp[i + 1][c2], INF);
        }
      }
    }
  }

  long long sum = 0;
  for (int c = 0; c < 26; c++) {
    sum = min(sum + dp[0][c], INF);
  }

  if (sum < K) {
    cout << "Eel" << endl;
    return;
  }

  string ans;
  for (int i = 0; i < N; i++) {
    char nxt = 'a';
    for (; nxt <= 'z'; nxt++) {
      if (dp[i][nxt - 'a'] >= K) break;
      K -= dp[i][nxt - 'a'];
    }
    ans += nxt;
    K--;
    if (K <= 0) break;
    while (S[i] != nxt) i++;
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
