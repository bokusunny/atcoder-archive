#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  long long ans = 0;
  for (int msk = 0; msk < 1 << N; msk++) {
    string s1, s2;
    for (int j = 0; j < N; j++) {
      if (msk >> j & 1) {
        s1 += S[j];
      } else {
        s2 += S[j];
      }
    }
    if ((int)s1.size() == 0 || (int)s2.size() == 0) continue;
    sort(s1.begin(), s1.end(), greater<char>());
    sort(s2.begin(), s2.end(), greater<char>());
    ans = max(ans, stoll(s1) * stoll(s2));
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
