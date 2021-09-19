#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  auto d = b / 2;

  // a:2, c:4, d:6
  long long ans = 0;
  long long dc = min(d, c);
  ans += dc;
  d -= dc;
  c -= dc;
  long long ac = min(a, c / 2);
  ans += ac;
  c -= ac * 2;
  a -= ac;
  long long ac2 = min(a / 3, c);
  ans += ac2;
  c -= ac2;
  a -= ac2 * 3;
  long long ad = min(d, a / 2);
  ans += ad;
  d -= ad;
  a -= ad * 2;
  ans += a / 5;

  cout << ans << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
