#include <bits/stdc++.h>
using namespace std;

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

int main() {
  long long N, A, B, K;
  cin >> N >> A >> B >> K;

  const long long MOD = 998244353;
  ModComb Comb(MOD, N);

  long long ans = 0;
  for (long long x = 0; A * x <= K; x++) {
    if ((K - A * x) % B != 0) continue;
    long long y = (K - A * x) / B;
    ans += Comb.get(N, x) * Comb.get(N, y) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
