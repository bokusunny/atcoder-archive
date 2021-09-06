#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<int> Rui(N + 1);
  for (int i = 0; i < N; i++) Rui[i + 1] = (Rui[i] + A[i]) % K;

  map<int, int> Cnt;
  vector<int> Memo(N + 1);
  long long ans = 0;
  for (int R = 0; R <= N; R++) {
    int val = ((Rui[R] - R) % K + K) % K;
    ans += Cnt[val];
    Cnt[val]++;
    if (R + 1 >= K) Cnt[Memo[R + 1 - K]]--;
    Memo[R] = val;
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
