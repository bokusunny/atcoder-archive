#include <bits/stdc++.h>
using namespace std;

struct Eratosthenes {
 private:
  int _n;
  vector<bool> IsPrime;
  vector<int> MinFactor;
  vector<int> Mobius;

 public:
  Eratosthenes(int n) : _n(n), IsPrime(n + 1, true), MinFactor(n + 1, -1), Mobius(n + 1, 1) {
    IsPrime[0] = IsPrime[1] = false;
    for (int p = 2; p <= n; p++) {
      if (!IsPrime[p]) continue;
      MinFactor[p] = p;
      Mobius[p] = -1;

      for (int q = 2 * p; q <= n; q += p) {
        IsPrime[q] = false;
        if (MinFactor[q] == -1) MinFactor[q] = p;
        if (q / p % p == 0) {
          Mobius[q] = 0;
        } else {
          Mobius[q] = -Mobius[q];
        }
      }
    }
  }

  bool is_prime(int x) { return IsPrime[x]; }

  vector<int> primes() {
    vector<int> res;
    for (int i = 2; i <= _n; i++) {
      if (IsPrime[i]) res.push_back(i);
    }
    return res;
  }

  vector<pair<int, int>> factorize(int n) {
    assert(2 <= n && n <= _n);

    vector<pair<int, int>> res;
    while (n > 1) {
      auto p = MinFactor[n];
      int ex = 0;
      while (MinFactor[n] == p) {
        ex++;
        n /= p;
      }
      res.emplace_back(p, ex);
    }

    return res;
  }

  vector<int> divisors(int n) {
    vector<int> res = {1};
    auto pf = factorize(n);
    for (auto [p, ex] : pf) {
      int sz = (int)res.size();
      for (int i = 0; i < sz; i++) {
        int v = 1;
        for (int j = 0; j < ex; j++) {
          v *= p;
          res.push_back(res[i] * v);
        }
      }
    }

    return res;
  }

  vector<int> get_mobius() { return Mobius; }
};

template <class T>
void fast_mobius(vector<T> &f) {
  int n = (int)f.size() - 1;
  Eratosthenes E(n);
  for (int p = 2; p <= n; p++) {
    if (!E.is_prime(p)) continue;
    for (int k = 1; k * p <= n; k++) {
      f[k] -= f[k * p];
    }
  }
}

void solve() {
  int L, R;
  cin >> L >> R;
  vector<long long> f(R + 1);
  for (int i = 1; i <= R; i++) {
    long long multi = R / i - (L - 1) / i;
    f[i] = multi * (multi - 1) / 2;
  }
  fast_mobius(f);
  long long ans = 0;
  for (int i = 2; i <= R; i++) ans += f[i];
  for (int i = max(2, L); i <= R; i++) ans -= R / i - 1;

  cout << ans * 2 << endl;
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
