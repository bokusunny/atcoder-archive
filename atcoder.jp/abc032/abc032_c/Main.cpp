#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  if (count(S.begin(), S.end(), 0) > 0) {
    cout << N << endl;
    return;
  }
  long long rui = 1;
  int ans = 0;
  int l = 0, r = 0;
  while (r < N) {
    if (l == r) {
      r++;
      rui *= S[l];
    } else if (rui <= K) {
      rui *= S[r];
      r++;
    } else {
      rui /= S[l];
      l++;
    }
    if (rui <= K) ans = max(ans, r - l);
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
