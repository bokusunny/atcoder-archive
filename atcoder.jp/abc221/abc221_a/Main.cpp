#include <bits/stdc++.h>
using namespace std;

void solve() {
  int A, B;
  cin >> A >> B;
  long long ans = 1;
  for (int i = 0; i < (A - B); i++) {
    ans *= 32;
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
