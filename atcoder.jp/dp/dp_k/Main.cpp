#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> A(n);
  for (auto &a : A) cin >> a;

  vector<bool> dp(k + 1, false);
  for (int i = 0; i < k; i++) {
    if (dp.at(i) == true) continue;
    for (auto a : A) {
      if (i + a <= k) dp.at(i + a) = true;
    }
  }

  if (dp.at(k)) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

  return 0;
}
