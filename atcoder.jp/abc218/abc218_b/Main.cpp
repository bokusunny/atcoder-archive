#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> P(26);
  for (int i = 0; i < 26; i++) cin >> P[i];
  string ans;
  for (int i = 0; i < 26; i++) {
    ans.push_back((char)('a' + P[i] - 1));
  }

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
