#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long mod = 1000000007) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long my_factorial(long long n, long long mod = 1000000007) {
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans = ans * i % mod;
  }

  return ans;
}

long long my_comb(long long n, long long k, long long mod = 1000000007) {
  long long ans = 1;
  ans = ans * my_factorial(n, mod) % mod;
  ans = ans * modpow(my_factorial(n - k, mod), mod - 2, mod) % mod;
  ans = ans * modpow(my_factorial(k, mod), mod - 2, mod) % mod;

  return ans;
}

int main() {
  int n, l;
  cin >> n >> l;

  if (n < l) {
    cout << 1 << endl;
    return 0;
  }

  const long long mod = 1000000007;

  long long ans = 0;
  int max_l_cnt = n / l;
  for (int l_cnt = 0; l_cnt <= max_l_cnt; l_cnt++) {
    int one_cnt = n - l * l_cnt;
    ans += my_comb(l_cnt + one_cnt, l_cnt);
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
