#include <bits/stdc++.h>
using namespace std;

void solve() {
  int S, T;
  cin >> S >> T;

  int cnt = 0;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++) {
        if (i + j + k <= S && i * j * k <= T) cnt++;
      }
    }
  }

  cout << cnt << endl;
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
