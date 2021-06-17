#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  vector<long long> H(n);
  for (auto &h : H) cin >> h;

  auto is_ok = [&](long long k) {
    vector<long long> HK;
    for (auto h : H) {
      if (k * b < h) HK.push_back(h - k * b);
    }
    for (auto h : HK) {
      k -= (h + a - b - 1) / (a - b);
      if (k < 0) return false;
    }

    return true;
  };

  long long ng = -1, ok = 1000000001;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
