#include <bits/stdc++.h>
using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  auto d = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

long long modinv(long long a, long long m = 1e9 + 7) {
  assert(m > 0 && gcd(a, m) == 1);

  long long x, y;
  extgcd(a, m, x, y);

  return (x % m + m) % m;  // xが負の場合に対応
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long N, S, K;
    cin >> N >> S >> K;
    auto g = gcd(N, K);
    if (S % g != 0) {
      cout << -1 << endl;
      continue;
    }
    N /= g, S /= g, K /= g;
    cout << (N - S) * modinv(K, N) % N << endl;
  }

  return 0;
}
