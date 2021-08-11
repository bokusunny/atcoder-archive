#include <bits/stdc++.h>
using namespace std;

#include <atcoder/string>
using namespace atcoder;

void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    auto s = S.substr(i);
    auto Len = z_algorithm(s);
    for (int j = 1; j < (int)Len.size(); j++) {
      if (Len[j] > j) continue;
      ans = max(ans, Len[j]);
    }
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
