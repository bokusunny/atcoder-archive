#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

void solve() {
  int N, K;
  cin >> N >> K;
  int MX = 300100;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  segtree<S, op, e> seg(MX);
  for (auto a : A) {
    auto prev_len = seg.prod(max(0, a - K), min(MX, a + K + 1));
    seg.set(a, prev_len + 1);
  }

  int ans = 0;
  for (int i = 0; i < MX; i++) {
    ans = max(ans, seg.get(i));
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
