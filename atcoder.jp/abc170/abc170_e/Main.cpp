#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

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
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; i++) node.at(i + n - 1) = v.at(i);
    for (int i = n - 2; i >= 0; i--) node.at(i) = min(node.at(2 * i + 1), node.at(2 * i + 2));
  }

  long long get(int x) { return node[n - 1 + x]; }

  void set(int x, long long val) {
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
  int N, Q;
  cin >> N >> Q;

  const int vec_size = 200010;

  vector<multiset<long long>> En(vec_size);  // 各園に所属する園児のレート集合
  vector<pair<int, long long>> Infant(N);    // 施設、rate
  vector<long long> V(vec_size, -1LL);       // 各園の最低rate

  for (int i = 0; i < N; i++) {
    long long A;
    int B;
    cin >> A >> B;
    B--;
    En[B].insert(A);
    Infant[i] = {B, A};
    chmax(V[B], A);
  }
  for (auto& v : V) {
    if (v == -1LL) v = INF;
  }

  SegTree seg(V);

  for (int q = 0; q < Q; q++) {
    int C, D;
    cin >> C >> D;
    C--, D--;

    // 園児情報の更新
    auto [prev_en, rate] = Infant[C];

    // prevのsegtree, Enを更新
    if (En[prev_en].size() == 1) {
      seg.set(prev_en, INF);
    } else {
      if (seg.get(prev_en) == rate) {
        auto begin_itr = En[prev_en].rbegin();
        begin_itr++;
        seg.set(prev_en, *begin_itr);
      }
    }
    auto itr = En[prev_en].find(rate);
    assert(itr != En[prev_en].end());
    En[prev_en].erase(itr);
    // newの情報set
    Infant[C].first = D;
    if (En[D].size() == 0 || seg.get(D) < rate) seg.set(D, rate);
    En[D].insert(rate);

    cout << seg.get_min(0, vec_size) << endl;
  }

  return 0;
}
