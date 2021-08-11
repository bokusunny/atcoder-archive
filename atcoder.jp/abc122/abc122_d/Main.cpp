#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int N;
  cin >> N;

  // dp[i][pre][prepre][preprepre] := i文字目まで見て最後がpre, その前がpreのものの数
  // "AGCT"
  using vmint = vector<mint>;
  vector<vector<vector<vmint>>> dp(N + 1, vector<vector<vmint>>(4, vector<vmint>(4, vmint(4))));
  for (int prepre = 0; prepre < 4; prepre++) {
    for (int pre = 0; pre < 4; pre++) {
      for (int nxt = 0; nxt < 4; nxt++) {
        if (prepre == 0 && pre == 1 && nxt == 2) continue;
        if (prepre == 1 && pre == 0 && nxt == 2) continue;
        if (prepre == 0 && pre == 2 && nxt == 1) continue;
        dp[3][nxt][pre][prepre] = 1;
      }
    }
  }

  for (int i = 3; i < N; i++) {
    for (int preprepre = 0; preprepre < 4; preprepre++) {
      for (int prepre = 0; prepre < 4; prepre++) {
        for (int pre = 0; pre < 4; pre++) {
          for (int nxt = 0; nxt < 4; nxt++) {
            if (prepre == 0 && pre == 1 && nxt == 2) continue;
            if (prepre == 1 && pre == 0 && nxt == 2) continue;
            if (prepre == 0 && pre == 2 && nxt == 1) continue;
            if (preprepre == 0 && pre == 1 && nxt == 2) continue;
            if (preprepre == 0 && prepre == 1 && nxt == 2) continue;

            dp[i + 1][nxt][pre][prepre] += dp[i][pre][prepre][preprepre];
          }
        }
      }
    }
  }

  mint ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        ans += dp[N][i][j][k];
      }
    }
  }

  cout << ans.val() << endl;
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
