#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  if (n * 2LL > m) {
    cout << m / 2 << endl;
    return 0;
  }

  long long ans = n;
  m -= 2LL * n;
  ans += m / 4LL;

  cout << ans << endl;

  return 0;
}
