#include <bits/stdc++.h>
using namespace std;

int A, B, C, D;

void solve() {
  cin >> A >> B >> C >> D;
  int i = 1;
  while (A > 0 || C > 0) {
    if (i & 1) {
      C -= B;
    } else {
      A -= D;
    }
    if (C <= 0) {
      cout << "Yes" << endl;
      return;
    } else if (A <= 0) {
      cout << "No" << endl;
      return;
    }
    i++;
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
