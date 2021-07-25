#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

struct ModnCk {
 private:
  vector<long long> Fac;
  long long MOD;

  long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
      if (n & 1) res = res * a % MOD;
      a = a * a % MOD;
      n >>= 1;
    }
    return res;
  }

 public:
  ModnCk(long long mod = 1e9 + 7, int size = 1 << 20) {
    MOD = mod;
    Fac.resize(size);
    Fac[0] = 1;
    for (int i = 1; i < size; i++) {
      Fac[i] = Fac[i - 1] * i % mod;
    }
  }

  long long get(long long n, long long k) {
    long long res = Fac[n];
    res = res * modpow(Fac[n - k], MOD - 2) % MOD;
    res = res * modpow(Fac[k], MOD - 2) % MOD;

    return res;
  }
};

const int mod = 1e9 + 7;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  ModnCk nCk;

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (i + 1 >= K) {
      ans += nCk.get(i, K - 1) * A[i] % mod;
      ans %= mod;
    }
    if (N - i >= K) {
      ans -= nCk.get(N - i - 1, K - 1) * A[i] % mod;
      ans %= mod;
    }
  }

  cout << ans << endl;

  return 0;
}
