#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

struct ModComb {
 private:
  vector<long long> Fac, Finv, Inv;
  long long MOD;
  int MAX_N;

  bool is_prime(long long x) {
    if (x == 1) return false;

    long long i = 2;
    while (i * i <= x) {
      if (x % i == 0) return false;
      i++;
    }
    return true;
  }

 public:
  ModComb(long long mod = 1e9 + 7, int max_n = 1 << 20) {
    assert(is_prime(mod) && mod > max_n);

    MOD = mod, MAX_N = max_n;
    Fac.resize(MAX_N + 1), Finv.resize(MAX_N + 1), Inv.resize(MAX_N + 1);
    Fac[0] = Fac[1] = 1;
    Finv[0] = Finv[1] = 1;
    Inv[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
      Fac[i] = Fac[i - 1] * i % MOD;
      Inv[i] = MOD - Inv[MOD % i] * (MOD / i) % MOD;
      Finv[i] = Finv[i - 1] * Inv[i] % MOD;
    }
  }

  long long get(int n, int k) {
    assert(n <= MAX_N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return Fac[n] * (Finv[k] * Finv[n - k] % MOD) % MOD;
  }
};

int R, C, X, Y, D, L;
ModComb Comb(1e9 + 7, 1000);

mint calc() {
  int k = D + L;

  // all
  mint res = Comb.get(X * Y, k);
  // 1
  res -= Comb.get((X - 1) * Y, k) * 2;
  res -= Comb.get(X * (Y - 1), k) * 2;
  // 2
  if (X >= 2) res += Comb.get((X - 2) * Y, k);
  if (Y >= 2) res += Comb.get(X * (Y - 2), k);
  res += Comb.get((X - 1) * (Y - 1), k) * 4;
  // 3
  if (X >= 2) res -= Comb.get((X - 2) * (Y - 1), k) * 2;
  if (Y >= 2) res -= Comb.get((X - 1) * (Y - 2), k) * 2;
  // 4
  if (X >= 2 && Y >= 2) res += Comb.get((X - 2) * (Y - 2), k);

  return res;
}

int main() {
  cin >> R >> C >> X >> Y >> D >> L;

  mint ans = 1;
  ans *= calc();
  ans *= Comb.get(D + L, D);
  ans *= (R - X + 1) * (C - Y + 1);

  cout << ans.val() << endl;

  return 0;
}
