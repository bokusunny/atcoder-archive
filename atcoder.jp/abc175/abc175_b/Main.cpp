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
      for (int k = j + 1; k < n; k++) {
        if (A.at(i) + A.at(j) <= A.at(k)) continue;
        if (A.at(k) + A.at(j) <= A.at(i)) continue;
        if (A.at(i) + A.at(k) <= A.at(j)) continue;
        if (A.at(i)==A.at(j)) continue;
        if (A.at(k)==A.at(j)) continue;
        if (A.at(i)==A.at(k)) continue;
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
