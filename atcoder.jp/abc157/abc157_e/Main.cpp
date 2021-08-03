#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = long long;
S op(S a, S b) { return a | b; }
S e() { return 0; }

int N, Q;
string s;

void solve() {
  cin >> N >> s >> Q;
  vector<long long> v(N);
  for (int i = 0; i < N; i++) {
    v[i] = 1LL << (s[i] - 'a');
  }
  segtree<S, op, e> seg(v);

  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      seg.set(i, (1LL << (c - 'a')));
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      cout << __builtin_popcount(seg.prod(l, r)) << endl;
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
