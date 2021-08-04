#include <bits/stdc++.h>
using namespace std;

int A, B;

void solve() {
  cin >> A >> B;
  for (int i = 0; i <= 100000; i++) {
    if (i * 8 / 100 == A && i * 10 / 100 == B) {
      cout << i << endl;
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
