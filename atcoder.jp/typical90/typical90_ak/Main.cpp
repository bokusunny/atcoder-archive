#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;

const long long INF = 1LL << 60;
long long op(long long a, long long b) { return max(a, b); }
long long e() { return -INF; }

int main() {
  long long w, n;
  cin >> w >> n;
  vector<segtree<long long, op, e>> dp(n + 1);
  for (int i = 0; i < n + 1; i++) {
    segtree<long long, op, e> seg(w + 1);
    dp.at(i) = seg;
  }
  dp.at(0).set(0, 0);

  for (int i = 1; i <= n; i++) {
    int l, r;
    long long v;
    cin >> l >> r >> v;

    for (int j = 0; j <= w; j++) {
      dp.at(i).set(j, max(dp.at(i).get(j), dp.at(i - 1).get(j)));
      dp.at(i).set(j, max(dp.at(i).get(j), dp.at(i - 1).prod(max(0, j - r), max(0, j - l + 1)) + v));
    }
  }

  if (dp.at(n).get(w) < 0)
    cout << -1 << endl;
  else
    cout << dp.at(n).get(w) << endl;

  return 0;
}
