#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    auto a = A.at(i);
    ans += -1LL * a * (n - 1 - i);
    ans += a * i;
  }

  cout << ans << endl;

  return 0;
}
