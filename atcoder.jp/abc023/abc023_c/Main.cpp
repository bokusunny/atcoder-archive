#include <bits/stdc++.h>
using namespace std;

void solve() {
  int R, C, K, N;
  cin >> R >> C >> K >> N;
  vector<int> RCnt(R), CCnt(C);
  vector<pair<int, int>> I(N);
  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;
    r--, c--;
    RCnt[r]++;
    CCnt[c]++;
    I[i] = {r, c};
  }

  vector<int> Num(N + 1);
  for (int i = 0; i < C; i++) Num[CCnt[i]]++;

  long long ans = 0;
  for (auto cnt : RCnt) {
    if (K >= cnt) ans += Num[K - cnt];
  }
  for (auto [r, c] : I) {
    if (RCnt[r] + CCnt[c] == K) ans--;
    if (RCnt[r] + CCnt[c] == K + 1) ans++;
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
