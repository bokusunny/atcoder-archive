#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long X, Y;
  cin >> X >> Y;
  if (Y > X) swap(X, Y);

  if (X == Y) {
    cout << "Brown" << endl;
  } else if ((X - Y) % 3 == 0) {
    cout << "Alice" << endl;
  } else if (X - Y == 1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
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
