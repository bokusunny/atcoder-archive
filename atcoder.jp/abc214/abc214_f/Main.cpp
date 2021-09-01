#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  vector Next(N + 1, vector<int>(26, -1));  // アルファベットjのうち1-indexedでi番目以降で最左のもののindex
  for (int i = N; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      if (S[i - 1] - 'a' == j) {
        Next[i][j] = i;
      } else if (i != N) {
        Next[i][j] = Next[i + 1][j];
      }
    }
  }

  vector<mint> dp(N + 1);
  dp[0] = 1;
  for (int j = 0; j < 26; j++) {
    if (Next[1][j] != -1) {
      dp[Next[1][j]] += dp[0];
    }
  }
  for (int i = 1; i < N - 1; i++) {
    for (int j = 0; j < 26; j++) {
      if (Next[i + 2][j] != -1) {
        dp[Next[i + 2][j]] += dp[i];
      }
    }
  }

  cout << (accumulate(dp.begin(), dp.end(), (mint)0) - 1).val() << endl;
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
