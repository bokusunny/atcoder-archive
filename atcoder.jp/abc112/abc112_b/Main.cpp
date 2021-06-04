#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, T;
  cin >> n >> T;

  int ans = 1001;
  for (int i = 0; i < n; i++) {
    int c, t;
    cin >> c >> t;

    if (t > T) continue;
    if (c < ans) ans = c;
  }

  if (ans != 1001) {
    cout << ans << endl;
  } else {
    cout << "TLE" << endl;
  }

  return 0;
}
