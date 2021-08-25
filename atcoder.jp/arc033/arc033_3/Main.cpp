#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
 private:
  int _n;
  vector<T> data;

 public:
  BIT(int n) : _n(n), data(_n, 0) {}

  void add(int i, T x) {
    assert(0 <= i && i < _n);
    i++;
    while (i <= _n) {
      data[i - 1] += x;
      i += i & -i;
    }
  }

  T sum(int r) {
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

  int lower_bound(T w) {
    int sz = 1;
    while (sz < _n) sz <<= 1;

    int res = 0;
    while (sz > 0) {
      if (res + sz < _n && data[res + sz - 1] < w) {
        w -= data[res + sz - 1];
        res += sz;
      }
      sz >>= 1;
    }

    return res;
  }
};

void solve() {
  int Q;
  cin >> Q;
  const int MX = 200010;
  BIT<int> Bit(MX);
  while (Q--) {
    int T, X;
    cin >> T >> X;
    if (T == 1) {
      Bit.add(X, 1);
    } else {
      auto x = Bit.lower_bound(X);
      cout << x << endl;
      Bit.add(x, -1);
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
