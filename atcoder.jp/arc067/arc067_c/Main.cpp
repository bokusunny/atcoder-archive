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

  T C(int n, int k) {
    assert(n <= MAX_N);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return Fac[n] * Finv[k] * Finv[n - k];
  }

  T H(int n, int r) { return C(n + r - 1, r); }

  T P(int n, int r) {
    assert(n <= MAX_N);
    assert(0 <= r && r <= n);
    return Fac[n] / Fac[n - r];
  }

  T get_fac(int n) {
    assert(0 <= n && n <= MAX_N);
    return Fac[n];
  }
};

void solve() {
  int N;
  cin >> N;
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  ModComb<mint> Comb(1 << 10);

  vector dp(B + 1, vector<mint>(N + 1));  // dp[i][j] := i人以下のグループのみでj人使っている場合の和
  dp[A - 1][0] = 1;
  for (int i = A; i <= B; i++) {
    for (int j = 0; j <= N; j++) {
      // i人のグループが0個の場合
      dp[i][j] += dp[i - 1][j];
      // i人のグループがk個の場合
      for (int k = C; k <= D; k++) {
        if (j - k * i < 0) break;
        mint choose = Comb.C(N - (j - k * i), i * k);
        mint assign = Comb.get_fac(k * i) / Comb.get_fac(k) / Comb.get_fac(i).pow(k);
        dp[i][j] += dp[i - 1][j - k * i] * choose * assign;
      }
    }
  }

  cout << dp[B][N].val() << endl;
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
