#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

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
  long long n;
  cin >> n;

  auto dv = divisors(n);

  long long ans = my_pow(10, 12) + 1;
  for (auto d : dv) {
    long long p = n / d;
    long long tmp = (d - 1) + (p - 1);
    if (tmp < ans) ans = tmp;
  }

  cout << ans << endl;

  return 0;
}
