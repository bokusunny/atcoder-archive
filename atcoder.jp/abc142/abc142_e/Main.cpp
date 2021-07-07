#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> Cost(M), Keys(M);
  for (int i = 0; i < M; i++) {
    int b;
    cin >> Cost[i] >> b;
    int bit = 0;
    for (int j = 0; j < b; j++) {
      int c;
      cin >> c;
      c--;
      bit |= (1 << c);
    }
    Keys[i] = bit;
  }

  const int INF = 1000000001;
  vector<int> dp(1 << N, INF);
  dp[0] = 0;
  for (int i = 0; i < 1 << N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i | Keys[j]] = min(dp[i | Keys[j]], dp[i] + Cost[j]);
    }
  }

  int ans = dp[(1 << N) - 1] != INF ? dp[(1 << N) - 1] : -1;
  cout << ans << endl;

  return 0;
}
