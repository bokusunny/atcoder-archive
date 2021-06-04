#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int tmp = A.at(i) * A.at(j);
      ans += tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
