#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, vector<pair<int, int>>> mp;

bool check(int msk) {
  auto X = __builtin_popcount(msk);
  for (auto [Y, Z] : mp[X]) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (msk >> i & 1) {
        if (i + 1 <= Y) cnt++;
      }
    }
    if (cnt > Z) return false;
  }
  return true;
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    mp[X].emplace_back(Y, Z);
  }

  vector<long long> dp(1 << N);  // dp[msk] := 集合mskで条件を満たすものの個数
  dp[0] = 1;
  for (int msk = 0; msk < 1 << N; msk++) {
    // 次に追加する数
    for (int j = 0; j < N; j++) {
      if (msk >> j & 1) continue;
      if (!check(msk | (1 << j))) continue;
      dp[msk | (1 << j)] += dp[msk];
    }
  }

  cout << dp[(1 << N) - 1] << endl;
}

int main() {
  solve();

  return 0;
}
