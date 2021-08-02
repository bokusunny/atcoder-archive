#include <bits/stdc++.h>
using namespace std;

char S, T;

void solve() {
  cin >> S >> T;
  if (S == 'Y') {
    cout << (char)('A' + T - 'a') << endl;
  } else {
    cout << T << endl;
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
