#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, q;
  cin >> n >> q;

  vector<long long> A(n);
  for (auto &a : A) cin >> a;

  for (int i = 0; i < q; i++) {
    long long k;
    cin >> k;

    auto is_ok = [&](long long x) {
      auto i = upper_bound(A.begin(), A.end(), x) - A.begin();
      return x - k < i;
    };

    long long ok = -1, ng = 2e18;

    while (abs(ok - ng) > 1) {
      long long mid = (ok + ng) / 2;
      if (is_ok(mid))
        ok = mid;
      else
        ng = mid;
    }

    cout << ok + 1 << endl;
  }

  return 0;
}
