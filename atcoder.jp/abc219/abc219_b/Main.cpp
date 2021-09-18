#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<string> vec(3);
  for (int i = 0; i < 3; i++) cin >> vec[i];
  string T;
  cin >> T;
  string ans;
  for (auto c : T) ans += vec[c - '1'];

  cout << ans << endl;
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
