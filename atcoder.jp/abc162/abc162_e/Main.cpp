#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

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
  long long N, K;
  cin >> N >> K;

  vector<mint> f(K + 1);
  for (int g = 1; g <= K; g++) {
    mint multi_cnt = K / g;
    f[g] = multi_cnt.pow(N);
  }
  fast_mobius(f);
  mint ans = 0;
  for (int g = 1; g <= K; g++) {
    ans += f[g] * g;
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
