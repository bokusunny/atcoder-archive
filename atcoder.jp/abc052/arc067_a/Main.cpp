#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

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
  int n;
  cin >> n;
  const long long mod = 1000000007;

  vector<int> ex(1001, 0);
  map<int, int> dic;
  for (int i = 2; i <= n; i++) {
    auto pf = prime_factorize(i);
    for (auto p : pf) ex[p.first] += p.second;
  }

  long long ans = 1;
  for (int e : ex) {
    ans = ans * (e + 1) % mod;
  }

  cout << ans << endl;

  return 0;
}
