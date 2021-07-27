#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

using S = long long;
using F = long long;
const long long INF = 1LL << 62;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S s) { return s <= 0 ? s : s + f; }
F composition(F f, F g) { return g + f; }
F id() { return 0; }

int main() {
  long long N, D, A;
  cin >> N >> D >> A;

  vector<pair<int, int>> XH(N);
  for (int i = 0; i < N; i++) cin >> XH[i].first >> XH[i].second;
  sort(XH.begin(), XH.end());
  vector<long long> X(N), H(N);
  for (int i = 0; i < N; i++) {
    X[i] = XH[i].first;
    H[i] = XH[i].second;
  }

  vector<int> R(N);
  for (int i = 0; i < N; i++) {
    R[i] = upper_bound(X.begin(), X.end(), X[i] + 2 * D) - X.begin();
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(H);

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    auto h = seg.get(i);
    if (h <= 0) continue;
    auto cnt = h % A == 0 ? h / A : h / A + 1;
    seg.apply(i, R[i], cnt * -A);
    ans += cnt;
  }

  cout << ans << endl;

  return 0;
}
