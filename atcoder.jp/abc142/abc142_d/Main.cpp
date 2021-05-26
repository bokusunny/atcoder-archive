#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  long long a, b;
  cin >> a >> b;

  long long g = gcd(a, b);
  
  auto prime_factorize = [](long long n) {
    set<long long> res;
    while (n % 2 == 0) {
      res.insert(2);
      n /= 2;
    }
    long long f = 3;
    while (f * f <= n) {
      if (n % f == 0) {
        res.insert(f);
        n /= f;
      } else {
        f += 2;
      }
    }

    if (n != 1) res.insert(n);

    return res;
  };

  cout << prime_factorize(g).size() + 1 << endl;

  return 0;
}
