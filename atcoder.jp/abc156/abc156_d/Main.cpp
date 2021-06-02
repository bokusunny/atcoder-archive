#include <bits/stdc++.h>
using namespace std;

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
  long long ans = 1;
  for (int i = 0; i < k; i++) ans = ans * (n - i) % mod;
  for (int i = 1; i <= k; i++) ans = ans * mod_pow(i, mod - 2, mod) % mod;

  return ans;
}

int mod_min(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  const long long MOD = 1e9 + 7;

  long long ans = mod_pow(2, n) - 1;
  ans = mod_min(ans - mod_nCk(n, a), MOD);
  ans = mod_min(ans - mod_nCk(n, b), MOD);

  cout << ans << endl;

  return 0;
}
