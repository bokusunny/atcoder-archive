#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

// aiから抽出した情報s[l, r)の型, using S = int;などでも可
struct S {
  mint sum;
  int len;
};
// 更新クエリの情報の型
struct F {
  mint b, c;
};

S op(S a, S b) { return {a.sum + b.sum, a.len + b.len}; }
S e() { return {0, 0}; }
// 更新クエリによってs[l, r)がどうなるか
S mapping(F f, S x) { return {f.b * x.sum + f.c * x.len, x.len}; }
// 2種類の更新クエリをg, fの順番で適用した場合にどのクエリと等価になるか
F composition(F f, F g) { return {f.b * g.b, f.b * g.c + f.c}; }
// 何も起きない更新クエリ
F id() { return {1, 0}; };

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<S> A(N);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    A[i] = {a, 1};
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

  while (Q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      long long b, c;
      cin >> b >> c;
      seg.apply(l, r, {b, c});
    } else {
      cout << seg.prod(l, r).sum.val() << endl;
    }
  }

  return 0;
}
