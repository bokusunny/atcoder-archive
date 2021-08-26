#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  const long long INF = 1LL << 62;
  long long mi = -INF, mx = INF, bonus = 0;
  for (int i = 0; i < N; i++) {
    int t;
    long long a;
    cin >> a >> t;
    if (t == 1) {
      bonus += a;
      mx += a;
      mi += a;
    } else if (t == 2) {
      mi = max(mi, a);
      mx = max(mi, mx);
    } else {
      mx = min(mx, a);
      mi = min(mx, mi);
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    long long x;
    cin >> x;
    auto ans = x + bonus;
    ans = min(ans, mx);
    ans = max(ans, mi);
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
