#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  auto is_ok = [&](long long x) { return a + b * x <= d * c * x; };

  long long ng = -1, ok = 1000000001;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  if (ok == 1000000001) {
    cout << -1 << endl;
  } else {
    cout << ok << endl;
  }

  return 0;
}
