#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> Cnt(3);
  cin >> Cnt[0] >> Cnt[1] >> Cnt[2];
  sort(Cnt.begin(), Cnt.end());

  const int INF = 1 << 30;
  int ans = INF;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      // Cnt[0]とCnt[1]を合わせる
      if ((Cnt[j] - Cnt[i]) % 3 != 0) continue;
      int cnt = (Cnt[j] - Cnt[i]) / 3;
      ans = min(ans, 3 * cnt + Cnt[i]);
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
