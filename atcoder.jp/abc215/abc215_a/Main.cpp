#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  if (S == "Hello,World!") {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
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
