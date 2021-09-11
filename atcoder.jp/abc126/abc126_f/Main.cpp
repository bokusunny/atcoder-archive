#include <bits/stdc++.h>
using namespace std;

void solve() {
  int M, K;
  cin >> M >> K;

  if ((1 << M) <= K) {
    cout << -1 << endl;
    return;
  }

  if (K == 0) {
    for (int i = 0; i < 1 << M; i++) {
      for (int j = 0; j < 2; j++) {
        cout << i << " ";
      }
    }
    cout << endl;
    return;
  }

  int xor_sum = 0;
  vector<int> ans({K});
  vector<int> add;
  for (int i = 0; i < 1 << M; i++) {
    if (i == K) continue;
    xor_sum ^= i;
    ans.push_back(i);
    add.push_back(i);
  }
  if (xor_sum != K) {
    cout << -1 << endl;
    return;
  }
  reverse(add.begin(), add.end());
  ans.push_back(K);
  for (auto val : add) ans.push_back(val);

  for (int i = 0; i < 1 << (M + 1); i++) {
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
