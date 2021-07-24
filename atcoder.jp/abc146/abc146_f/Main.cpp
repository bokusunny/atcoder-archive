#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 62;
struct SegTree {
 private:
  int n;
  vector<long long> node;

 public:
  SegTree(vector<long long> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; i++) node.at(i + n - 1) = v.at(i);
    for (int i = n - 2; i >= 0; i--) node.at(i) = min(node.at(2 * i + 1), node.at(2 * i + 2));
  }

  long long get(int x) { return node[x + n - 1]; }

  void update(int x, long long val) {
    x += n - 1;
    node.at(x) = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node.at(x) = min(node.at(2 * x + 1), node.at(2 * x + 2));
    }
  }

  // [l, r): 要求区間
  // k: 自分が今いるノード
  // [a, b): kがカバーする区間
  long long get_min(int l, int r, int k = 0, int a = 0, int b = -1) {
    assert(0 <= l && r <= n && l < r);
    if (b == -1) b = n;  // 初期値設定

    if (b <= l || r <= a) return INF;         // 要求区間とカバー区間が交わらない
    if (l <= a && b <= r) return node.at(k);  // 要求区間がカバー区間を完全被覆

    long long vl = get_min(l, r, 2 * k + 1, a, (a + b) / 2);
    long long vr = get_min(l, r, 2 * k + 2, (a + b) / 2, b);
    return min(vl, vr);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;

  vector<long long> dp(N + 1, INF);
  vector<long long> memo(N + 1, INF);
  dp[N] = 0;
  memo[0] = N;
  SegTree seg(dp);
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '1') continue;
    auto cost = seg.get_min(i + 1, min(N + 1, i + M + 1)) + 1;
    if (seg.get(i) <= cost) continue;
    seg.update(i, cost);
    memo[cost] = i;
  }

  if (seg.get(0) == INF) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (memo[i + 1] == INF) break;
    ans.push_back(memo[i] - memo[i + 1]);
  }

  int sz = (int)ans.size();
  for (int i = sz - 1; i >= 0; i--) {
    if (i != sz - 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
