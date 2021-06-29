#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

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

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());
  const int max = 1000100;

  vector<bool> is_ok(max, true);
  vector<bool> seen(max, false);
  for (auto a : A) {
    if (!is_ok[a]) continue;
    if (seen[a]) {
      is_ok[a] = false;
      continue;
    } else {
      seen[a] = true;
    }
    for (int i = a * 2; i < max; i += a) {
      is_ok[i] = false;
    }
  }

  int ans = 0;
  for (auto a : A)
    if (is_ok[a]) ans++;
  cout << ans << endl;

  return 0;
}
