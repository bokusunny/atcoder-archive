#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for (int i = 0; i < M; i++) cin >> A[i];
  sort(A.begin(), A.end());
  vector<int> MatchCnt = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};  // MatchCnt[i] := 数字iが必要とするマッチ棒の本数

  vector<string> dp(N + 1);
  for (auto &a : A) {
    if (MatchCnt[a] > N) continue;
    dp[MatchCnt[a]] = to_string(a);
  }
  for (int i = 0; i < N; i++) {
    if ((int)dp[i].size() == 0) continue;
    for (auto &a : A) {
      if (i + MatchCnt[a] > N) continue;
      string tmp = dp[i] + to_string(a);
      sort(tmp.begin(), tmp.end(), greater<char>());
      int tsize = (int)tmp.size(), nxtsize = (int)dp[i + MatchCnt[a]].size();
      if (tsize > nxtsize || (tsize == nxtsize && tmp > dp[i + MatchCnt[a]])) {
        dp[i + MatchCnt[a]] = tmp;
      }
    }
  }

  cout << dp.back() << endl;
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
