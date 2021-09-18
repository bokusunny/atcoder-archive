#include <bits/stdc++.h>
using namespace std;

void solve() {
  int X;
  cin >> X;
  if (X < 40) {
    cout << 40 - X << endl;
  } else if (X < 70) {
    cout << 70 - X << endl;
  } else if (X < 90) {
    cout << 90 - X << endl;
  } else {
    cout << "expert" << endl;
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
