#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

int N, Q;
vector<mint> one, ten;

// aiから抽出した情報s[l, r)の型, using S = int;などでも可
struct S {
  mint sum;
  int len;
};
// 更新クエリの情報の型
using F = int;

S op(S a, S b) { return {a.sum * ten[b.len] + b.sum, a.len + b.len}; }
S e() { return {0, 0}; }
// 更新クエリによってs[l, r)がどうなるか
S mapping(F f, S x) {
  if (f == -1) return x;
  return {f * one[x.len], x.len};
}
// 2種類の更新クエリをg, fの順番で適用した場合にどのクエリと等価になるか
F composition(F f, F g) {
  if (f == -1) return g;
  return f;
}
// 何も起きない更新クエリ
F id() { return -1; };

void init() {
  one.resize(N + 1), ten.resize(N + 1);
  one[1] = ten[0] = 1;
  for (int i = 2; i <= N; i++) one[i] = one[i - 1] * 10 + 1;
  for (int i = 1; i <= N; i++) ten[i] = ten[i - 1] * 10;
}

int main() {
  cin >> N >> Q;
  init();
  vector<S> V(N, {1, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(V);

  while (Q--) {
    int L, R, D;
    cin >> L >> R >> D;
    L--;
    seg.apply(L, R, D);
    cout << seg.all_prod().sum.val() << endl;
  }

  return 0;
}
