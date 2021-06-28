#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = int;  // change if necessary
S op(S a, S b) { return a ^ b; }
S e() { return 0; }
// segtree<S, op, e> seg(A);

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  segtree<S, op, e> seg(A);

  while (Q--) {
    int T;
    cin >> T;
    long long X, Y;
    cin >> X >> Y;
    X--;
    if (T == 1) {
      auto A = seg.get(X);
      seg.set(X, A ^ Y);
    } else {
      cout << seg.prod(X, Y) << endl;
    }
  }

  return 0;
}
