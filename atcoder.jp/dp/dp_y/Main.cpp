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
  ModComb(long long mod = 1e9 + 7, int max_n = 1 << 20) {
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

int H, W, N;
vector<pair<int, int>> Wall;

void solve() {
  cin >> H >> W >> N;
  Wall.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> Wall[i].first >> Wall[i].second;
    Wall[i].first--, Wall[i].second--;
  }
  Wall.emplace_back(0, 0);
  Wall.emplace_back(H - 1, W - 1);
  sort(Wall.begin(), Wall.end());
  N = (int)Wall.size();

  ModComb Comb;

  vector<vector<mint>> dp(N, vector<mint>(2));
  dp[0][1] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      auto yi = Wall[i].first, yj = Wall[j].first;
      auto xi = Wall[i].second, xj = Wall[j].second;
      if (yi > yj || xi > xj) continue;
      dp[j][0] += dp[i][1] * Comb.get((yj - yi) + (xj - xi), (yj - yi));
      dp[j][1] += dp[i][0] * Comb.get((yj - yi) + (xj - xi), (yj - yi));
    }
  }

  cout << (dp[N - 1][0] - dp[N - 1][1]).val() << endl;
}

int main() {
  solve();

  return 0;
}
