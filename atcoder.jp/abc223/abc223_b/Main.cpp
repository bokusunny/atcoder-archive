#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  string ans1 = S, ans2 = S;
  for (int i = 0; i < N; i++) {
    rotate(S.begin(), S.begin() + 1, S.end());
    ans1 = min(ans1, S);
    ans2 = max(ans2, S);
  }

  cout << ans1 << endl << ans2 << endl;
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
