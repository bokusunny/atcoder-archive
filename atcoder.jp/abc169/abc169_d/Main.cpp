#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<pair<T, int>> prime_factorize(T N) {
  vector<pair<T, int>> res;
  for (T i = 2; i * i <= N; i++) {
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

void solve() {
  long long N;
  cin >> N;
  auto pf = prime_factorize(N);
  int ans = 0;
  for (auto [p, ex] : pf) {
    int cnt = 0, sum = 0;
    while (ex >= sum + cnt + 1) {
      cnt++;
      sum += cnt;
    }
    ans += cnt;
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
