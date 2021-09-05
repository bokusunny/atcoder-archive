#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }

void solve() {
  int N;
  cin >> N;
  map<int, vector<int>> P;
  for (int i = 0; i < N; i++) {
    int h, w;
    cin >> h >> w;
    P[h].push_back(w);
  }

  segtree<S, op, e> seg(100010);
  for (auto [h, vec] : P) {
    vector<pair<int, int>> Q;
    for (auto w : vec) {
      auto mx = seg.prod(0, w);
      Q.emplace_back(w, mx + 1);
    }
    for (auto [w, val] : Q) {
      seg.set(w, max(val, seg.get(w)));
    }
  }

  cout << seg.all_prod() << endl;
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
