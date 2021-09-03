#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
 private:
  int _n;
  vector<T> data;

 public:
  BIT(int n) : _n(n), data(_n, 0) {}
  BIT(vector<T> &v) : _n((int)v.size()), data(_n, 0) {
    for (int i = 0; i < _n; i++) add(i, v[i]);
  }

  void add(int i, T x) {
    assert(0 <= i && i < _n);
    i++;
    while (i <= _n) {
      data[i - 1] += x;
      i += i & -i;
    }
  }

  T get(int i) {
    assert(0 <= i && i < _n);
    return sum(i, i + 1);
  }

  void set(int i, T x) {
    assert(0 <= i && i < _n);
    auto cur = get(i);
    add(i, x - cur);
  }

  T sum(int r) {
    assert(0 <= r && r <= _n);
    T res = 0;
    while (r > 0) {
      res += data[r - 1];
      r -= r & -r;
    }
    return res;
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }
};

using T = tuple<int, int, int>;

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> C(N);
  for (int i = 0; i < N; i++) cin >> C[i], C[i]--;
  vector<T> Query(Q);
  for (int i = 0; i < Q; i++) {
    cin >> get<0>(Query[i]) >> get<1>(Query[i]);
    get<2>(Query[i]) = i;
    get<0>(Query[i])--;
  }
  auto comp = [](const T &a, const T &b) { return get<1>(a) < get<1>(b); };
  sort(Query.begin(), Query.end(), comp);

  vector<int> ans(Q);
  vector<int> Pos(N, -1);  // Pos[i] := 既出のi色の玉で一番右のもののindex
  BIT<int> Bit(N);
  int cur = 0;
  for (auto [l, r, i] : Query) {
    while (cur < r) {
      auto old_pos = Pos[C[cur]];
      if (old_pos != -1) Bit.set(old_pos, 0);
      Bit.set(cur, 1);
      Pos[C[cur]] = cur;
      cur++;
    }
    ans[i] = Bit.sum(l, r);
  }

  for (auto &a : ans) cout << a << endl;
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
