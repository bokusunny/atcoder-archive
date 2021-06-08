#include <bits/stdc++.h>
using namespace std;

auto is_prime(int x) {
  if (x == 1) return false;

  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i++;
  }
  return true;
}

auto spf(int n) {
  vector<int> spf_table(n + 1);
  for (int i = 0; i <= n; i++) spf_table.at(i) = i;
  for (int i = 2; i * i <= n; i++) {
    if (spf_table.at(i) != i) continue;

    for (int j = i * i; j <= n; j += i) {
      if (spf_table.at(j) != j) continue;
      spf_table.at(j) = i;
    }
  }

  return spf_table;
}

int main() {
  long long n;
  cin >> n;

  auto spf_table = spf(n);

  auto f = [&](long long k) {
    int prime = spf_table.at(k);
    int ex = 0;
    long long res = 1;
    while (k > 1) {
      auto target = spf_table.at(k);
      if (target == prime) {
        ex++;
      } else {
        res *= (ex + 1);
        prime = target;
        ex = 1;
      }
      k /= target;
    }

    res *= (ex + 1);
    return res;
  };

  long long ans = 0;
  for (long long k = 1; k <= n; k++) {
    ans += k * f(k);
  }

  cout << ans << endl;

  return 0;
}
