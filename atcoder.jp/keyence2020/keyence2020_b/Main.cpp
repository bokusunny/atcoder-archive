#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<pair<int, int>> LR(N);
  for (int i = 0; i < N; i++) {
    int X, L;
    cin >> X >> L;
    LR[i].first = X - L;
    LR[i].second = X + L;
  }
  sort(LR.begin(), LR.end(), [](auto const &x, auto const &y) { return x.second < y.second; });

  const int INF = 1 << 30;
  int ans = 0, last = -INF;
  for (auto [L, R] : LR) {
    if (L < last) continue;
    last = R;
    ans++;
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
