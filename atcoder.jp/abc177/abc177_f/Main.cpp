#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

struct SegVal {
  int l, min;
};
using F = int;
const int INF = 1 << 30;

SegVal op(SegVal a, SegVal b) { return {min(a.l, b.l), min(a.min, b.min)}; }
SegVal e() { return {INF, INF}; }
SegVal mapping(F f, SegVal x) {
  if (f == INF) return x;
  return {x.l, x.l + f};
}
F composition(F f, F g) {
  if (f == INF) return g;
  return f;
}
F id() { return INF; };

void solve() {
  int H, W;
  cin >> H >> W;
  vector<int> A(H), B(H);
  for (int i = 0; i < H; i++) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  vector<SegVal> Init(W);
  for (int i = 0; i < W; i++) Init[i] = {i, 0};
  lazy_segtree<SegVal, op, e, F, mapping, composition, id> seg(Init);

  for (int i = 0; i < H; i++) {
    auto x = A[i] == 0 ? W : seg.get(A[i] - 1).min;
    seg.apply(A[i], B[i] + 1, x - A[i] + 1);
    auto ans = seg.all_prod().min;
    if (ans >= W) {
      cout << -1 << endl;
    } else {
      cout << ans + i + 1 << endl;
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
