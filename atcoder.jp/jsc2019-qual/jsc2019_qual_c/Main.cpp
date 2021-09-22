#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int N;
  string S;
  cin >> N >> S;

  if (S.front() == 'W' || S.back() == 'W') {
    cout << 0 << endl;
    return;
  }

  mint fac = 1;
  for (int i = 1; i <= N; i++) fac *= i;

  vector<int> LR({0});  // 0:L, 1:R
  for (int i = 1; i < 2 * N; i++) {
    if (S[i] == S[i - 1]) {
      LR.push_back(!LR.back());
    } else {
      LR.push_back(LR.back());
    }
  }

  if (count(LR.begin(), LR.end(), 0) != count(LR.begin(), LR.end(), 1)) {
    cout << 0 << endl;
    return;
  }

  int lcnt = 0, rcnt = 0;
  mint ans = fac;
  for (int i = 0; i < 2 * N; i++) {
    if (LR[i]) ans *= (lcnt - rcnt);
    if (LR[i])
      rcnt++;
    else
      lcnt++;
  }

  cout << ans.val() << endl;
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
