#include <bits/stdc++.h>
using namespace std;

template <class T>
struct LazyBIT {
 private:
  int _n;
  vector<vector<T>> data;

  void add_(int p, int i, T x) {
    i++;
    while (i <= _n) {
      data[p][i - 1] += x;
      i += i & -i;
    }
  }

  T sum_(int p, int r) {
    T res = 0;
    while (r > 0) {
      res += data[p][r - 1];
      r -= r & -r;
    }
    return res;
  }

 public:
  LazyBIT(int n) : _n(n), data(2) {
    data[0].resize(_n);
    data[1].resize(_n);
  }
  LazyBIT(vector<T> &v) : _n((int)v.size()), data(2) {
    data[0].resize(_n);
    data[1].resize(_n);
    for (int i = 0; i < _n; i++) add(i, i + 1, v[i]);
  }

  void add(int l, int r, T x) {
    assert(0 <= l && l <= r && r <= _n);
    add_(0, l, -x * (l - 1));
    add_(0, r, x * (r - 1));
    add_(1, l, x);
    add_(1, r, -x);
  }

  T get(int i) {
    assert(0 <= i && i < _n);
    return sum(i, i + 1);
  }

  void set(int i, T x) {
    assert(0 <= i && i < _n);
    auto cur = get(i);
    add(i, i + 1, x - cur);
  }

  T sum(int r) {
    assert(0 <= r && r <= _n);
    return sum_(0, r) + sum_(1, r) * (r - 1);
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> V(N - 1, N - 2);
  LazyBIT<long long> Bit_y(V), Bit_x(V);
  int y_lim = N - 1, x_lim = N - 1;

  long long ans = 1LL * (N - 2) * (N - 2);
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      x--;

      ans -= Bit_x.get(x);
      if (x < x_lim) {
        auto lim = Bit_y.get(1);
        Bit_y.add(1, y_lim, x - 1 - lim);
        x_lim = x;
      }
    } else {
      int y;
      cin >> y;
      y--;

      ans -= Bit_y.get(y);
      if (y < y_lim) {
        auto lim = Bit_x.get(1);
        Bit_x.add(1, x_lim, y - 1 - lim);
        y_lim = y;
      }
    }
  }

  cout << ans << endl;
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
