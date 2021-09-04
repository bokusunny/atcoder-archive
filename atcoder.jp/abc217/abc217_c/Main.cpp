#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i], P[i]--;

  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans[P[i]] = i + 1;
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
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
