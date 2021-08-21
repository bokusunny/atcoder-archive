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
    for (long long i = 2; i <= n; i++) {
      if (!IsPrime[i]) continue;
      MinFactor[i] = i;
      Mobius[i] = -1;

      for (int j = 2 * i; j <= n; j += i) {
        IsPrime[j] = false;
        if (MinFactor[j] == -1) MinFactor[j] = i;
        if (i / j % i == 0) {
          Mobius[j] = 0;
        } else {
          Mobius[j] = -Mobius[j];
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
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  Eratosthenes E(100000);
  set<int> P;
  for (auto a : A) {
    if (a == 1) continue;
    auto pf = E.factorize(a);
    for (auto [p, ex] : pf) {
      P.insert(p);
    }
  }

  vector<int> ans({1});
  for (int k = 2; k <= M; k++) {
    auto pf = E.factorize(k);
    bool is_ok = true;
    for (auto [p, ex] : pf) {
      if (P.count(p)) {
        is_ok = false;
        break;
      }
    }
    if (is_ok) ans.push_back(k);
  }

  cout << (int)ans.size() << endl;
  for (auto a : ans) cout << a << endl;
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
