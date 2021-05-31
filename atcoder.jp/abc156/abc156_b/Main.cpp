#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int ans = 1;
  while (n >= k) {
    n /= k;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
