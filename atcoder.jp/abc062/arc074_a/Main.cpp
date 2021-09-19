#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long H, W;
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
  } else {
    long long ans = min(H, W);
    // 縦に割ってから横に割る場合
    for (int w = 1; w < W; w++) {
      vector<long long> P;
      P.push_back(1LL * w * H);
      P.push_back((W - w) * (H / 2));
      P.push_back(H * W - P[0] - P[1]);
      long long val = *max_element(P.begin(), P.end()) - *min_element(P.begin(), P.end());
      ans = min(ans, val);
    }
    // 横に割ってから縦に割る場合
    for (int h = 1; h < H; h++) {
      vector<long long> P;
      P.push_back(1LL * h * W);
      P.push_back((H - h) * (W / 2));
      P.push_back(H * W - P[0] - P[1]);
      long long val = *max_element(P.begin(), P.end()) - *min_element(P.begin(), P.end());
      ans = min(ans, val);
    }
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
