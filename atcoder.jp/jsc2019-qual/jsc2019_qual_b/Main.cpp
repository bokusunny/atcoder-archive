#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int n;
  long long k;
  cin >> n >> k;

  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vec[i] = a;
  }

  long long mod = pow(10, 9) + 7;

  vector<int> total_inversion_per_sequence(n, 0);
  vector<int> left_inversion_per_sequence(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (vec[i] > vec[j]) {
        total_inversion_per_sequence[i]++;
        if (j < i) left_inversion_per_sequence[i]++;
      }
    }
  }

  long long kC2 = (k + 1) * k % mod * modpow(2, mod - 2, mod) % mod;

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long tmp = total_inversion_per_sequence[i] * kC2 % mod -
                    (left_inversion_per_sequence[i] * k % mod);
    if (tmp < 0) tmp += mod;
    ans = (ans + tmp) % mod;
  }

  cout << ans % mod << endl;

  return 0;
}
