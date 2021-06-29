#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = int;  // change if necessary
S op(S a, S b) { return gcd(a, b); }
S e() { return 0; }

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;
  segtree<S, op, e> seg(A);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    auto l = seg.prod(0, i);
    auto r = seg.prod(i + 1, N);
    auto tmp = gcd(l, r);
    ans = max(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
