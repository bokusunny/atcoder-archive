#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> A(n);
  for (auto &a : A) cin >> a;

  map<long long, long long> m;
  for (auto a : A) m[a]++;

  long long ans = n * (n - 1) / 2;
  for (auto [i, cnt] : m) {
    ans -= cnt * (cnt - 1) / 2;
  }

  cout << ans << endl;

  return 0;
}
