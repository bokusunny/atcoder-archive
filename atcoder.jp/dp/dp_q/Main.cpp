#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
struct SegTree {
 private:
  int n;
  vector<long long> node;

 public:
  SegTree(vector<long long> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, -INF);
    for (int i = 0; i < sz; i++) node.at(i + n - 1) = v.at(i);
    for (int i = n - 2; i >= 0; i--) node.at(i) = max(node.at(2 * i + 1), node.at(2 * i + 2));
  }

  void update(int x, long long val) {
    x += n - 1;
    node.at(x) = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node.at(x) = max(node.at(2 * x + 1), node.at(2 * x + 2));
    }
  }

  // [l, r): 要求区間
  // k: 自分が今いるノード
  // [a, b): kがカバーする区間
  long long get_max(int l, int r, int k = 0, int a = 0, int b = -1) {
    assert(0 <= l && r <= n && l < r);
    if (b == -1) b = n;  // 初期値設定

    if (b <= l || r <= a) return -INF;        // 要求区間とカバー区間が交わらない
    if (l <= a && b <= r) return node.at(k);  // 要求区間がカバー区間を完全被覆

    long long vl = get_max(l, r, 2 * k + 1, a, (a + b) / 2);
    long long vr = get_max(l, r, 2 * k + 2, (a + b) / 2, b);
    return max(vl, vr);
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> dp(N + 1);
  auto seg = SegTree(dp);

  for (int i = 0; i < N; i++) {
    seg.update(H[i], seg.get_max(0, H[i]) + A[i]);
  }

  cout << seg.get_max(0, N + 1) << endl;

  return 0;
}
