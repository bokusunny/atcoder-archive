#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  const long long mod = 998244353;
  long long ans = 0;

  vector<long long> A(n);
  for (auto &a : A) {
    cin >> a;
    ans = (ans + (a * a % mod)) % mod;
  }
  sort(A.begin(), A.end());

  long long tmp = 0;

  for (int i = n - 1; i >= 0; i--) {
    ans = (ans + A[i] * tmp % mod) % mod;
    tmp = tmp * 2 % mod;
    tmp = (tmp + A[i]) % mod;
  }

  cout << ans << endl;

  return 0;
}
