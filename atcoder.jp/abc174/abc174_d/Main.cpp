#include <bits/stdc++.h>
using namespace std;

int N;
string S;

void solve() {
  cin >> N >> S;
  int lc = 0, rc = N - 1;
  int ans = 0;
  while (lc < rc) {
    if (S[lc] == 'W') {
      while (lc < rc) {
        if (S[rc] == 'R') {
          ans++;
          rc--;
          break;
        }
        rc--;
      }
    }
    lc++;
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
