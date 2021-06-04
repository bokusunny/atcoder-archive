#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> V(n);
  for (auto &a : V) cin >> a;
  vector<int> C(n);
  for (auto &a : C) cin >> a;

  for (int i = 0; i < n; i++) {
    int v = V.at(i), c = C.at(i);
    if (v - c > 0) ans += (v - c);
  }

  cout << ans << endl;

  return 0;
}
