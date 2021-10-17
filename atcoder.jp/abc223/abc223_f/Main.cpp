#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

// aiから抽出した情報s[l, r)の型, using S = int;などでも可
using SegVal = int;
// 更新クエリの情報の型
using F = int;

const int INF = 1 << 30;
SegVal op(SegVal a, SegVal b) { return min(a, b); }
SegVal e() { return INF; }
// 更新クエリによってs[l, r)がどうなるか
SegVal mapping(F f, SegVal x) { return x + f; }
// 2種類の更新クエリをg, fの順番で適用した場合にどのクエリと等価になるか
F composition(F f, F g) { return g + f; }
// 何も起きない更新クエリ
F id() { return 0; };

void solve() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      A[i] = 1;
    } else {
      A[i] = -1;
    }
  }
  vector<int> Rui(N + 1);
  for (int i = 0; i < N; i++) Rui[i + 1] = Rui[i] + A[i];
  lazy_segtree<SegVal, op, e, F, mapping, composition, id> Min(Rui);
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      l--;
      if (S[l] == '(' && S[r - 1] == ')') {
        Min.apply(l + 1, r, -2);
      } else if (S[l] == ')' && S[r - 1] == '(') {
        Min.apply(l + 1, r, 2);
      }
      swap(S[l], S[r - 1]);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      if (Min.get(l) == Min.get(r) && Min.prod(l, r) >= Min.get(l)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
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
