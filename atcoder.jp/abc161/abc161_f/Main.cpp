#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<T> divisors(T N) {
  vector<T> res;
  for (T i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

void solve() {
  long long N;
  cin >> N;

  if (N == 2) {
    cout << 1 << endl;
    return;
  }

  int ans = 0;

  // NがKで割り切れない時
  auto D1 = divisors(N - 1);
  for (auto k : D1) {
    if (k == 1 || N % k == 0) continue;
    ans++;
  }

  // NがKで割り切れる時
  auto D2 = divisors(N);
  for (auto k : D2) {
    if (k == 1) continue;
    auto n = N;
    while (n % k == 0) n /= k;
    if (n % k == 1) ans++;
  }

  cout << ans << endl;
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
