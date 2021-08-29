#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a;
  char b, C;
  cin >> a >> b >> C;
  int c = C - '0';
  if (c <= 2) {
    cout << a << '-' << endl;
  } else if (c <= 6) {
    cout << a << endl;
  } else {
    cout << a << '+' << endl;
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
