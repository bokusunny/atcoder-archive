#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, D;
  cin >> H >> W >> D;
  vector A(H, vector<int>(W));
  vector<pair<int, int>> Zahyo(H * W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      A[i][j]--;
      Zahyo[A[i][j]] = {i, j};
    }
  }

  vector S(D, vector<int>(1));
  for (int mo = 0; mo < D; mo++) {
    for (int i = 1; mo + i * D < H * W; i++) {
      auto cur = Zahyo[mo + i * D];
      auto prev = Zahyo[mo + (i - 1) * D];
      auto cost = abs(cur.first - prev.first) + abs(cur.second - prev.second);
      S[mo].push_back(S[mo][i - 1] + cost);
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    auto mo = L % D;
    auto ans = S[mo][R / D] - S[mo][L / D];
    cout << ans << endl;
  }
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
