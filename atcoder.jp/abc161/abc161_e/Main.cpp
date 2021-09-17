#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;

  vector<int> dp(N + 1);           // i日目終了時点での最大稼働日数
  vector<vector<int>> Pre(N + 1);  // i日目への遷移元
  for (int i = 0; i < N; i++) {
    if (dp[i] > dp[i + 1]) {
      Pre[i + 1].clear();
      dp[i + 1] = dp[i];
      Pre[i + 1].push_back(i);
    } else if (dp[i + 1] == dp[i]) {
      Pre[i + 1].push_back(i);
    }
    if (S[i] == 'o') {
      if (dp[i] + 1 > dp[min(i + 1 + C, N)]) {
        Pre[min(i + 1 + C, N)].clear();
        dp[min(i + 1 + C, N)] = dp[i] + 1;
        Pre[min(i + 1 + C, N)].push_back(i);
      } else if (dp[min(i + 1 + C, N)] == dp[i] + 1) {
        Pre[min(i + 1 + C, N)].push_back(i);
      }
    }
  }

  assert(dp[N] >= K);
  if (dp[N] > K) return;

  queue<int> q;
  vector<bool> Seen(N + 1);
  q.push(N);
  Seen[N] = true;
  vector<vector<int>> Choice(K);  // i-1日目の稼働日の候補

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto pu : Pre[u]) {
      if (!Seen[pu]) {
        Seen[pu] = true;
        q.push(pu);
      }
      if (dp[u] == dp[pu] + 1) {
        Choice[dp[pu]].push_back(pu + 1);
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < K; i++) {
    if ((int)Choice[i].size() == 1) ans.push_back(Choice[i][0]);
  }

  for (auto &a : ans) cout << a << endl;
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
