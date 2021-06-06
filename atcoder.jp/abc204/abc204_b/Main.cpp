#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a = A.at(i);
    if (a > 10) {
      ans += a - 10;
    }
  }

  cout << ans << endl;

  return 0;
}
