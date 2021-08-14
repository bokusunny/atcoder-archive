#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  if (N <= 125) {
    cout << 4 << endl;
  } else if (N <= 211) {
    cout << 6 << endl;
  } else {
    cout << 8 << endl;
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
