#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> Box, vector<pair<int, int>> Nimotsu) {
  vector<bool> used((int)Box.size(), false);
  int ans = 0;
  for (auto [v, w] : Nimotsu) {
    for (int i = 0; i < (int)Box.size(); i++) {
      if (used[i] || w > Box[i]) continue;
      ans += v;
      used[i] = true;
      break;
    }
  }
  cout << ans << endl;
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<pair<int, int>> Nimotsu(N);
  for (int i = 0; i < N; i++) {
    int W, V;
    cin >> W >> V;
    Nimotsu[i] = {V, W};
  }
  sort(Nimotsu.begin(), Nimotsu.end(), greater<pair<int, int>>());

  vector<int> Box(M);
  for (int i = 0; i < M; i++) cin >> Box[i];

  while (Q--) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    vector<int> leftBox;
    for (int i = 0; i < L; i++) leftBox.push_back(Box[i]);
    for (int i = R + 1; i < M; i++) leftBox.push_back(Box[i]);
    sort(leftBox.begin(), leftBox.end());
    solve(leftBox, Nimotsu);
  }

  return 0;
}
