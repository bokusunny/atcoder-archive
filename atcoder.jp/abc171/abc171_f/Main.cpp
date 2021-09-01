#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

struct ModComb {
 private:
  vector<long long> Fac, Finv, Inv;
  long long MOD;
  int MAX_N;

  bool is_prime(long long x) {
    if (x == 1) return false;

    long long i = 2;
    while (i * i <= x) {
      if (x % i == 0) return false;
      i++;
    }
    return true;
  }

 public:
  ModComb(long long mod = 1e9 + 7, int max_n = 1 << 22) {
    assert(is_prime(mod) && mod > max_n);

    MOD = mod, MAX_N = max_n;
    Fac.resize(MAX_N + 1), Finv.resize(MAX_N + 1), Inv.resize(MAX_N + 1);
    Fac[0] = Fac[1] = 1;
    Finv[0] = Finv[1] = 1;
    Inv[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
      Fac[i] = Fac[i - 1] * i % MOD;
      Inv[i] = MOD - Inv[MOD % i] * (MOD / i) % MOD;
      Finv[i] = Finv[i - 1] * Inv[i] % MOD;
    }
  }

  long long get(int n, int k) {
    assert(n <= MAX_N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return Fac[n] * (Finv[k] * Finv[n - k] % MOD) % MOD;
  }
};

void solve() {
  int K;
  string S;
  cin >> K >> S;
  int N = (int)S.size();

  ModComb Comb;

  mint ans = 0;
  for (int k = 0; k <= K; k++) {
    mint tmp = 1;
    mint num = 26;
    tmp *= num.pow(k);
    num--;
    tmp *= Comb.get(N + K - k - 1, N - 1);
    tmp *= num.pow(K - k);
    ans += tmp;
  }

  cout << ans.val() << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
