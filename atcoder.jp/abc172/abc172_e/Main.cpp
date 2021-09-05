#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

template <class T>
struct ModComb {
 private:
  vector<T> Fac, Finv, Inv;
  int MAX_N;

 public:
  ModComb(int max_n = 1 << 20) {
    MAX_N = max_n;
    Fac.resize(MAX_N + 1), Finv.resize(MAX_N + 1), Inv.resize(MAX_N + 1);
    Fac[0] = Fac[1] = 1;
    Finv[0] = Finv[1] = 1;
    Inv[1] = 1;

    int MOD = T::mod();
    for (int i = 2; i <= MAX_N; i++) {
      Fac[i] = Fac[i - 1] * i;
      Inv[i] = MOD - Inv[MOD % i] * (MOD / i);
      Finv[i] = Finv[i - 1] * Inv[i];
    }
  }

  T nCk(int n, int k) {
    assert(n <= MAX_N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return Fac[n] * Finv[k] * Finv[n - k];
  }

  T nHr(int n, int r) { return nCk(n + r - 1, r); }

  T nPr(int n, int r) {
    assert(n <= MAX_N);
    assert(0 <= r && r <= n);
    return Fac[n] / Fac[n - r];
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  ModComb<mint> Comb;

  mint ans = 0;
  for (int same = 0; same <= N; same++) {
    mint tmp = 1;
    tmp *= Comb.nCk(N, same);
    tmp *= Comb.nPr(M, same);
    tmp *= Comb.nPr(M - same, N - same);
    tmp *= Comb.nPr(M - same, N - same);
    if (same & 1) {
      ans -= tmp;
    } else {
      ans += tmp;
    }
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
