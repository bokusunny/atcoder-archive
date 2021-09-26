#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 0; i < 2000; i++) {
    if (a <= c * i && c * i <= b) {
      cout << c * i << endl;
      return;
    }
  }
  cout << -1 << endl;
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
