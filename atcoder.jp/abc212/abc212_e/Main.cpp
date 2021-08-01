#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

int N, M, K;
vector<vector<int>> NG;

void solve() {
  cin >> N >> M >> K;
  NG.resize(N);
  for (int i = 0; i < M; i++) {
    int U, V;
    cin >> U >> V;
    U--, V--;
    NG[U].push_back(V);
    NG[V].push_back(U);
  }

  vector<vector<mint>> dp(K + 1, vector<mint>(N));
  dp[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    mint sum = 0;
    for (auto val : dp[i - 1]) sum += val;
    for (int j = 0; j < N; j++) {
      dp[i][j] = sum;
      dp[i][j] -= dp[i - 1][j];
      for (auto v : NG[j]) {
        dp[i][j] -= dp[i - 1][v];
      }
    }
  }

  cout << dp[K][0].val() << endl;
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
