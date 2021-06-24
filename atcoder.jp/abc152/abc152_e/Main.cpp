#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

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

map<int, int> lcm_map(vector<long long> V) {
  map<int, int> lcm_M;
  for (auto a : V) {
    auto pf = prime_factorize(a);
    for (auto [val, ex] : pf) {
      if (lcm_M[val] < ex) lcm_M[val] = ex;
    }
  }

  return lcm_M;
}

long long mod_pow(long long a, long long n, int mod = 1000000007) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (auto &a : A) cin >> a;

  auto M = lcm_map(A);

  mint l = 1;
  for (auto [val, ex] : M) l *= mod_pow(val, ex);

  mint ans = 0;
  for (auto a : A) {
    mint ma = a;
    ans += l / ma;
  }

  cout << ans.val() << endl;

  return 0;
}
