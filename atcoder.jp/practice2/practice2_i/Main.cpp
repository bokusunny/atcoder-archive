#include <bits/stdc++.h>
using namespace std;

#include <atcoder/string>
using namespace atcoder;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();
  auto sa = suffix_array(S);

  long long ans = 1LL * N * (N + 1) / 2;
  for (auto len : lcp_array(S, sa)) ans -= len;

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
