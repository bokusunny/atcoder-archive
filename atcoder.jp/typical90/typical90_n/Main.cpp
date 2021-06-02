#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> A(n);
  for (auto &a : A) cin >> a;
  vector<long long> B(n);
  for (auto &b : B) cin >> b;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(A[i] - B[i]);
  }

  cout << ans << endl;
  return 0;
}
