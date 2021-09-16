#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<long long> ans(N + 1);
  for (int x = 1; x * x < N; x++) {
    for (int y = 1; y * y < N; y++) {
      for (int z = 1; z * z < N; z++) {
        long long tmp = 1LL * x * x + y * y + z * z + x * y + y * z + x * z;
        if (1 <= tmp && tmp <= N) {
          ans[tmp]++;
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) cout << ans[i] << endl;
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
