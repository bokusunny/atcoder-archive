#include <bits/stdc++.h>
using namespace std;

int A, B;

void solve() {
  cin >> A >> B;
  if (A > 12) {
    cout << B << endl;
  } else if (6 <= A) {
    cout << B / 2 << endl;
  } else {
    cout << 0 << endl;
  }
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
