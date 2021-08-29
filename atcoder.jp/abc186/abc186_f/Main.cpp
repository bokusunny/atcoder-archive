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

void solve() {
  int H, W, M;
  cin >> H >> W >> M;
  int y_lim = H, x_lim = W;
  vector<int> X(M), Y(M);
  for (int i = 0; i < M; i++) {
    cin >> Y[i] >> X[i];
    Y[i]--, X[i]--;
    if (X[i] == 0) y_lim = min(y_lim, Y[i]);
    if (Y[i] == 0) x_lim = min(x_lim, X[i]);
  }
  vector Wall1(x_lim, vector<int>({H})), Wall2(y_lim, vector<int>{W});
  for (int i = 0; i < M; i++) {
    if (X[i] < x_lim) Wall1[X[i]].push_back(Y[i]);
    if (Y[i] < y_lim) Wall2[Y[i]].push_back(X[i]);
  }
  for (auto &v : Wall1) sort(v.begin(), v.end());
  for (auto &v : Wall2) sort(v.begin(), v.end());

  long long cnt = 0;
  for (int i = 0; i < x_lim; i++) cnt += Wall1[i][0];
  for (int i = 0; i < y_lim; i++) cnt += Wall2[i][0];

  vector<int> V(y_lim, 1);
  BIT<int> Bit(V);
  for (int i = 0; i < x_lim; i++) {
    cnt -= Bit.sum(min(y_lim, Wall1[i][0]));
    for (auto &w : Wall1[i]) {
      if (w < y_lim) Bit.set(w, 0);
    }
  }

  cout << cnt << endl;
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
