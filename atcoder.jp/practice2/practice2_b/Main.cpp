#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = long long;
S op(S a, S b) { return a + b; }
S e() { return 0LL; }

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  segtree<S, op, e> seg(A);

  while (Q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      long long x;
      cin >> p >> x;
      seg.set(p, seg.get(p) + x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r) << endl;
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
