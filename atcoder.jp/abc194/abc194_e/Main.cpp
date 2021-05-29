#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  vector<int> cnt(2000000, 0);
  int ans = 0;
  for (int i = 0; i < m; i++) cnt[A[i]]++;
  for (int i = 0; i < (int)cnt.size(); i++) {
    if (cnt[i] != 0) continue;

    ans = i;
    break;
  }

  for (int i = 0; i < n - m; i++) {
    cnt[A[i + m]]++;
    cnt[A[i]]--;
    if (cnt[A[i]] == 0 && A[i] < ans) ans = A[i];
  }

  cout << ans << endl;

  return 0;
}
