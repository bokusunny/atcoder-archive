#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

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
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (auto &a : A) cin >> a;
  vector<int> v(60);  // 各bitが1の要素が何個あるか
  for (auto a : A) {
    for (int i = 0; i < 60; i++) {
      if (a >> i & 1) v[i]++;
    }
  }

  mint ans = 0;
  for (auto a : A) {
    for (int i = 0; i < 60; i++) {
      if (a >> i & 1) {
        ans += mod_pow(2, i) * (n - v[i]);
      }
    }
  }

  cout << ans.val() << endl;

  return 0;
}
