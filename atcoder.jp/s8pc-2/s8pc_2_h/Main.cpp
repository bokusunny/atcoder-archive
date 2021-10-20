#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

struct SegVal {
  int val;
  int sz;
};
using F = int;

SegVal op(SegVal a, SegVal b) { return {a.val + b.val, a.sz + b.sz}; }
SegVal e() { return {0, 0}; }
SegVal mapping(F f, SegVal x) {
  if (f) x.val = x.sz - x.val;
  return x;
}
F composition(F f, F g) { return f ^ g; }
F id() { return 0; };

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<SegVal> Init(N, {0, 1});
  lazy_segtree<SegVal, op, e, F, mapping, composition, id> seg(Init);

  while (Q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      seg.apply(l, r, 1);
    } else {
      cout << seg.prod(l, r).val << endl;
    }
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
