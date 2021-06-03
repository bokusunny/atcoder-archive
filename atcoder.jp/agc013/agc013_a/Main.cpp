#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  vector<int> V;
  for (int i = 0; i < n - 1; i++) {
    if (A.at(i) < A.at(i + 1)) {
      V.emplace_back(0);
    } else if (A.at(i) > A.at(i + 1)) {
      V.emplace_back(1);
    }
  }

  int ans = 1;
  for (int i = 0; i < (int)V.size() - 1; i++) {
    if (V.at(i) != V.at(i + 1)) {
      ans++;
      i++;
    }
  }

  cout << ans << endl;

  return 0;
}
