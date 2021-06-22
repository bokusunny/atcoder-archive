#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;

int target;
int op(int a, int b) { return max(a, b); }
int e() { return -1; }
bool f(int v) { return v < target; }

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  segtree<int, op, e> seg(A);

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      seg.set(x - 1, v);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l - 1, r) << endl;
    } else {
      int x;
      cin >> x >> target;
      cout << seg.max_right<f>(x - 1) + 1 << endl;
    }
  }

  return 0;
}
