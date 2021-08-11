#include <bits/stdc++.h>
using namespace std;

void solve() {
  int D, G;
  cin >> D >> G;
  vector<int> P(D), C(D);
  for (int i = 0; i < D; i++) cin >> P[i] >> C[i];

  const int INF = 1 << 30;
  int ans = INF;
  for (int msk = 0; msk < 1 << D; msk++) {
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < D; i++) {
      if (msk >> i & 1) {
        sum += 100 * (i + 1) * P[i] + C[i];
        cnt += P[i];
      }
    }
    if (G <= sum) {
      ans = min(ans, cnt);
      continue;
    }
    for (int i = D - 1; i >= 0; i--) {
      if (msk >> i & 1) continue;
      if (G - sum >= 100 * (i + 1) * P[i]) {
        cnt = INF;
      } else {
        cnt += (G - sum + 100 * (i + 1) - 1) / (100 * (i + 1));
      }
      break;
    }
    ans = min(ans, cnt);
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
