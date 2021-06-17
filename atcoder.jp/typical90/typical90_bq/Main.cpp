#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

long long mod_pow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  long long n, k;
  cin >> n >> k;
  const long long MOD = 1e9 + 7;

  if (n == 1) {
    cout << k << endl;
    return 0;
  } else if (n == 2) {
    if (k == 1) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << k * (k - 1) % MOD << endl;
      return 0;
    }
  }

  if (k <= 2) {
    cout << 0 << endl;
    return 0;
  }

  mint ans = 1;
  ans *= k;
  ans *= (k - 1);
  ans *= mod_pow(k - 2, n - 2, MOD);

  cout << ans.val() << endl;

  return 0;
}
