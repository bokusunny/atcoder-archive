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

  BIT<int> Bit(N);
  long long cnt = 0;
  for (int j = 0; j < N; j++) {
    cnt += j - Bit.sum(A[j] + 1);
    Bit.add(A[j], 1);
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
