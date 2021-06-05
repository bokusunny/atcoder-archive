#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &a : A) cin >> a;
  vector<int> B(n);
  for (auto &b : B) cin >> b;
  vector<int> C(n);
  for (auto &c : C) cin >> c;
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());

  long long ans = 0;
  for (auto b : B) {
    auto a = lower_bound(A.begin(), A.end(), b) - A.begin();
    auto c = C.end() - upper_bound(C.begin(), C.end(), b);
    ans += a * c;
  }

  cout << ans << endl;

  return 0;
}
