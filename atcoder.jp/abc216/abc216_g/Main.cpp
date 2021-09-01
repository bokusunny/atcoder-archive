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
  int N, M;
  cin >> N >> M;
  vector A(M, vector<int>(3));
  for (int i = 0; i < M; i++) {
    cin >> A[i][0] >> A[i][1] >> A[i][2];
    A[i][0]--;
  }

  auto comp = [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; };
  sort(A.begin(), A.end(), comp);

  BIT<int> Bit(N);
  stack<int> Empty;
  int pre_r = 0;
  for (auto v : A) {
    int L = v[0], R = v[1], X = v[2];
    for (int i = pre_r; i < R; i++) {
      if (Bit.get(i) == 0) Empty.push(i);
    }
    auto cnt = Bit.sum(L, R);
    for (int i = 0; i < X - cnt; i++) {
      auto j = Empty.top();
      Empty.pop();
      Bit.add(j, 1);
    }
    pre_r = R;
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << Bit.get(i);
  }
  cout << endl;
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
