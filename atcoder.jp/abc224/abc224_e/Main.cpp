#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, N;
  cin >> H >> W >> N;

  vector<int> R(N), C(N), A(N);
  for (int i = 0; i < N; i++) {
    cin >> R[i] >> C[i] >> A[i];
    R[i]--, C[i]--;
  }
  map<int, vector<int>, greater<int>> mp;
  for (int i = 0; i < N; i++) mp[A[i]].push_back(i);
  vector<int> ans(N);

  vector<int> RMax(H), CMax(W);
  for (auto [a, vec] : mp) {
    for (auto &i : vec) ans[i] = max(RMax[R[i]], CMax[C[i]]);
    for (auto &i : vec) {
      RMax[R[i]] = max(RMax[R[i]], ans[i] + 1);
      CMax[C[i]] = max(CMax[C[i]], ans[i] + 1);
    }
  }

  for (auto &a : ans) cout << a << endl;
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
