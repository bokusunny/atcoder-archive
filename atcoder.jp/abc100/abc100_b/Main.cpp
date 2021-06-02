#include <bits/stdc++.h>
using namespace std;

long long my_pow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  long long d, n;
  cin >> d >> n;

  long long ans = my_pow(100, d) * n;

  if (n == 100) {
    cout << ans + my_pow(100, d) << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
