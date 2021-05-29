#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prime_factorize(int N) {
  vector<pair<int, int>> res;
  for (int i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    int ex = 0;
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
  int p, q;
  cin >> p >> q;

  int g = gcd(p, q);
  int Q = q / g;
  auto pf = prime_factorize(Q);

  long long prime_prod = 1;
  for (auto p : pf) prime_prod *= p.first;

  cout << prime_prod << endl;

  return 0;
}
