#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S, T;
  cin >> S >> T;
  if (S < T) {
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
