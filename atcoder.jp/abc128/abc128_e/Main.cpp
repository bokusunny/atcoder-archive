#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
struct LazySegTree {
 private:
  int n;
  vector<long long> node, lazy;
  vector<bool> lazyFlag;

  // サボっていた評価を精算
  void eval(int k, int a, int b) {
    if (!lazyFlag.at(k)) return;

    node.at(k) = lazy.at(k);
    // kのカバーする区間(=b-a)が1以上 ⇔ kは葉ノードではない
    if (b - a > 1) {
      lazy.at(2 * k + 1) = lazy.at(2 * k + 2) = lazy.at(k);
      lazyFlag.at(2 * k + 1) = lazyFlag.at(2 * k + 2) = true;
    }

    lazyFlag.at(k) = false;
  }

 public:
  LazySegTree(vector<long long> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, -INF);
    lazy.resize(2 * n - 1, 0);
    lazyFlag.resize(2 * n - 1, false);
    for (int i = 0; i < sz; i++) node.at(i + n - 1) = v.at(i);
    for (int i = n - 2; i >= 0; i--) node.at(i) = max(node.at(2 * i + 1), node.at(2 * i + 2));
  }

  void update(int l, int r, long long x, int k = 0, int a = 0, int b = -1) {
    assert(0 <= l && r <= n && l <= r);
    if (l == r) return;
    if (b == -1) b = n;

    eval(k, a, b);

    if (b <= l || r <= a) return;
    // 完全被覆なら、自分と子ノードの更新のみでサボる
    if (l <= a && b <= r) {
      lazy.at(k) = x;
      lazyFlag.at(k) = true;
      eval(k, a, b);
    } else {
      update(l, r, x, 2 * k + 1, a, (a + b) / 2);
      update(l, r, x, 2 * k + 2, (a + b) / 2, b);
      node.at(k) = max(node.at(2 * k + 1), node.at(2 * k + 2));
    }
  }

  long long get_max(int l, int r, int k = 0, int a = 0, int b = -1) {
    assert(0 <= l && r <= n && l < r);
    if (b == -1) b = n;  // 初期値設定

    if (b <= l || r <= a) return -INF;  // 要求区間とカバー区間が交わらない

    eval(k, a, b);
    if (l <= a && b <= r) return node.at(k);  // 要求区間がカバー区間を完全被覆

    long long vl = get_max(l, r, 2 * k + 1, a, (a + b) / 2);
    long long vr = get_max(l, r, 2 * k + 2, (a + b) / 2, b);
    return max(vl, vr);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  using T = tuple<int, int, int>;
  vector<T> W(N);
  for (int i = 0; i < N; i++) {
    cin >> get<0>(W[i]) >> get<1>(W[i]) >> get<2>(W[i]);
  }
  sort(W.begin(), W.end(), [](auto const a, auto const b) { return get<2>(a) > get<2>(b); });
  vector<int> D(Q);
  for (int i = 0; i < Q; i++) cin >> D[i];

  vector<long long> Pos(Q, -1);
  LazySegTree seg(Pos);

  for (int i = 0; i < N; i++) {
    auto [s, t, x] = W[i];
    int lower = s - x;
    int upper = t - x;
    int li = lower_bound(D.begin(), D.end(), lower) - D.begin();
    int ui = lower_bound(D.begin(), D.end(), upper) - D.begin();
    seg.update(li, ui, i);
  }

  for (int i = 0; i < Q; i++) {
    auto wi = seg.get_max(i, i + 1);
    if (wi == -1) {
      cout << -1 << endl;
    } else {
      cout << get<2>(W[wi]) << endl;
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
