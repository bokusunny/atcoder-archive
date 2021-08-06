#include <bits/stdc++.h>
using namespace std;

int N, M;

void solve() {
  cin >> N >> M;
  vector<pair<int, int>> AB(M);
  for (int i = 0; i < M; i++) {
    cin >> AB[i].second >> AB[i].first;
    AB[i].first--, AB[i].second--;
  }
  sort(AB.begin(), AB.end());

  int ans = 0, prev = 0;
  for (auto [B, A] : AB) {
    if (prev <= A) {
      ans++;
      prev = B;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
