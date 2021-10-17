#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x;
  cin >> x;
  if (x > 0 && x % 100 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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
