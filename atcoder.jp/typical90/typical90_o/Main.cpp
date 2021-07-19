#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
vector<long long> Fac, FacInv;
long long mod_pow(long long a, long long n, long long mod = 1000000007) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long mod_nCk(long long n, long long k, long long mod = 1000000007) {
  assert(n >= k);
  long long ans = 1;
  ans = ans * Fac[n] % mod;
  ans = ans * FacInv[n - k] % mod;
  ans = ans * FacInv[k] % mod;

  return ans;
}

int main() {
  long long N;
  cin >> N;

  Fac.assign(N + 1, 1), FacInv.resize(N + 1);
  for (int i = 2; i <= N; i++) Fac[i] = Fac[i - 1] * i % MOD;
  for (int i = 0; i <= N; i++) FacInv[i] = mod_pow(Fac[i], MOD - 2);

  for (long long k = 1; k <= N; k++) {
    long long ans = 0;
    for (long long a = 1; a <= N; a++) {
      if (N - (k - 1) * (a - 1) < a) break;
      ans += mod_nCk(N - (k - 1) * (a - 1), a);
      ans %= MOD;
    }
    cout << ans << endl;
  }

  return 0;
}
