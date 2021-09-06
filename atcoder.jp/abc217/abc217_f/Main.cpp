#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint998244353;

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
  vector IsPair(2 * N, vector<bool>(2 * N));
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    IsPair[A][B] = IsPair[B][A] = true;
  }

  ModComb<mint> Comb(300);
  vector memo(2 * N + 1, vector<mint>(2 * N + 1, -1));
  function<mint(int, int)> rec = [&](int l, int r) {
    if (memo[l][r] != -1) return memo[l][r];
    if (r == l) return memo[l][r] = 1;
    if (r - l == 2) {
      if (IsPair[l][r - 1]) {
        return memo[l][r] = 1;
      } else {
        return memo[l][r] = 0;
      }
    }

    mint res = 0;
    for (int m = l + 2; m <= r; m += 2) {
      if (!IsPair[l][m - 1]) continue;
      res += rec(l + 1, m - 1) * rec(m, r) * Comb.nCk((r - l) / 2, (m - l) / 2);
    }

    return memo[l][r] = res;
  };

  cout << rec(0, 2 * N).val() << endl;
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
