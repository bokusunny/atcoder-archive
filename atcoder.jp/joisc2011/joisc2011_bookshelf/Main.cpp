#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = long long;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

void solve() {
  int N;
  cin >> N;
  vector<long long> W(N);
  for (int i = 0; i < N; i++) cin >> W[i];
  vector<int> Order(N);
  for (int i = 0; i < N; i++) cin >> Order[i], Order[i]--;

  segtree<S, op, e> seg(N);
  long long sum = 0, tmp = 0;
  for (int i = 0; i < N; i++) {
    sum += W[Order[i]] * 2;
    auto mx_cost = seg.prod(0, Order[i]) + W[Order[i]] * 2;
    seg.set(Order[i], mx_cost);
    tmp = max(tmp, mx_cost);
  }

  cout << sum - tmp << endl;
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
