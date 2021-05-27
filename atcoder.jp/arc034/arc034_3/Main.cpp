#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> prime_factorize(long long N) {
  vector<pair<long long, long long>> res;
  for (long long i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    long long ex = 0;
    while (N % i == 0) {
      ex++;
      N /= i;
    }
    res.push_back({i, ex});
  }

  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  int a, b;
  cin >> a >> b;
  const long long mod = 1000000007;

  map<int, int> ex;
  for (int i = b + 1; i <= a; i++) {
    auto pf = prime_factorize(i);
    for (auto p : pf) ex[p.first] += p.second;
  }

  long long ans = 1;
  for (auto [prime, e] : ex) {
    ans = ans * (1 + e) % mod;
  }

  cout << ans << endl;

  return 0;
}
