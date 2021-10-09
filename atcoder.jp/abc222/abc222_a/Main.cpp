#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int cnt = 4 - (int)S.size();
  string l(cnt, '0');

  cout << l + S << endl;
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
