#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// aiから抽出した情報s[l, r)の型, using S = int;などでも可
struct S {
  long long c0, c1, val;
};
// 更新クエリの情報の型
using F = int;

S op(S a, S b) { return {a.c0 + b.c0, a.c1 + b.c1, a.val + b.val + a.c1 * b.c0}; }
S e() { return {0, 0, 0}; }
// 更新クエリによってs[l, r)がどうなるか
S mapping(F f, S x) {
  if (!f) return x;
  return {x.c1, x.c0, x.c1 * x.c0 - x.val};
}
// 2種類の更新クエリをg, fの順番で適用した場合にどのクエリと等価になるか
F composition(F f, F g) { return g ^ f; }
// 何も起きない更新クエリ
F id() { return 0; };

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<S> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 1)
      A[i] = {0, 1, 0};
    else
      A[i] = {1, 0, 0};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(A);

  while (Q--) {
    int T, L, R;
    cin >> T >> L >> R;
    L--;
    if (T == 1) {
      seg.apply(L, R, 1);
    } else {
      cout << seg.prod(L, R).val << endl;
    }
  }

  return 0;
}
