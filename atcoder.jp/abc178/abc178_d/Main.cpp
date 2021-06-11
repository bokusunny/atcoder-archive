#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

long long mod_pow(long long a, long long n, long long mod = 1000000007) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long mod_factorial(long long n, long long mod = 1000000007) {
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans = ans * i % mod;
  }

  return ans;
}

long long mod_nCk(long long n, long long k, long long mod = 1000000007) {
  long long ans = 1;
  ans = ans * mod_factorial(n, mod) % mod;
  ans = ans * mod_pow(mod_factorial(n - k, mod), mod - 2, mod) % mod;
  ans = ans * mod_pow(mod_factorial(k, mod), mod - 2, mod) % mod;

  return ans;
}

int main() {
  int s;
  cin >> s;

  if (s <= 2) {
    cout << 0 << endl;
    return 0;
  }

  mint ans = 0;
  for (int i = 1; i <= 666; i++) {
    int left = s - 3 * i;
    if (left < 0) break;
    ans += mod_nCk(left + i - 1, left);
  }

  cout << ans.val() << endl;

  return 0;
}
