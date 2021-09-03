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
    assert(1 <= n && n <= _n);

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

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  Eratosthenes E(100010);
  vector<int> Cnt(100010);
  for (auto &a : A) {
    auto Dv = E.divisors(a);
    for (auto &d : Dv) Cnt[d]++;
  }
  for (int i = 1; i <= M; i++) {
    int ans = 0;
    auto pf = E.factorize(i);
    for (int msk = 0; msk < 1 << (int)pf.size(); msk++) {
      int prod = 1;
      for (int j = 0; j < (int)pf.size(); j++) {
        if (msk >> j & 1) prod *= pf[j].first;
      }
      if (__builtin_popcount(msk) & 1) {
        ans -= Cnt[prod];
      } else {
        ans += Cnt[prod];
      }
    }
    cout << ans << endl;
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
