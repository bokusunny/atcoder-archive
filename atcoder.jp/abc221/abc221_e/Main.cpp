#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

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

template <class T>
void compress(vector<T> &A) {
  auto A_ = A;
  sort(A_.begin(), A_.end());
  A_.erase(unique(A_.begin(), A_.end()), A_.end());
  for (auto &a : A) a = lower_bound(A_.begin(), A_.end(), a) - A_.begin();
}

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  compress(A);
  BIT<mint> Bit(N + 1);
  mint ans = 0, two = 2;
  auto inv = two.inv();
  for (int i = 0; i < N; i++) {
    if (i > 0) ans += two.pow(i - 1) * Bit.sum(A[i] + 1);
    Bit.add(A[i], inv.pow(i));
  }

  cout << ans.val() << endl;
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
