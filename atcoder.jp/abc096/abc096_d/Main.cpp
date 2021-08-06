#include <bits/stdc++.h>
using namespace std;

struct EnumeratePrimes {
 private:
  vector<bool> IsPrime;
  vector<int> Primes;

 public:
  EnumeratePrimes(int n) : IsPrime(n + 1, true) {
    IsPrime[0] = IsPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
      if (!IsPrime[i]) continue;

      for (int j = 2 * i; j <= n; j += i) {
        IsPrime[j] = false;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (IsPrime[i]) Primes.push_back(i);
    }
  }

  bool is_prime(int x) { return IsPrime[x]; }
  vector<int> get() { return Primes; }
};

int N;

void solve() {
  cin >> N;
  EnumeratePrimes EP(55555);
  auto primes = EP.get();
  vector<int> ans;
  for (auto p : primes) {
    if (p % 5 != 1) continue;
    ans.push_back(p);
    if ((int)ans.size() == N) break;
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  solve();

  return 0;
}
