#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<pair<int, int>> E;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    E.emplace_back(a, 1);
    E.emplace_back(a + b, -1);
  }
  sort(E.begin(), E.end());

  vector<int> ans(N + 1);
  int cnt = 0;
  for (int i = 0; i < 2 * N; i++) {
    if (i > 0) ans[cnt] += E[i].first - E[i - 1].first;
    cnt += E[i].second;
  }

  for (int i = 1; i <= N; i++) {
    if (i > 1) cout << " ";
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
