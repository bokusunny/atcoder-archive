#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long X;
  cin >> X;

  long long ans = 1;
  for (int p = 2; p <= 30; p++) {
    for (int b = 1; b < 100; b++) {
      long long tmp = 1;
      for (int i = 0; i < p; i++) {
        tmp *= b;
        if (tmp > X) break;
      }
      if (tmp <= X) ans = max(ans, tmp);
    }
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
