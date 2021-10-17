#include <bits/stdc++.h>
using namespace std;

void solve() {
  int X, Y;
  cin >> X >> Y;
  vector<long long> ABC(3);
  for (int i = 0; i < 3; i++) cin >> ABC[i];

  if (1LL * X * Y < accumulate(ABC.begin(), ABC.end(), 0LL)) {
    cout << "No" << endl;
    return;
  }

  auto is_ok = [](int x, int y, long long a, long long b) {
    long long aa = (a + (x - 1)) / x;
    long long bb = (b + (x - 1)) / x;
    return aa + bb <= y;
  };

  for (int t = 0; t < 2; t++) {
    if (t & 1) swap(X, Y);
    // ABC[i]を下に入れる
    for (int i = 0; i < 3; i++) {
      int YY = Y - (ABC[i] + (X - 1)) / X;
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        for (int k = j + 1; k < 3; k++) {
          if (i == k) continue;
          if (is_ok(X, YY, ABC[j], ABC[k]) || (YY > 0 && is_ok(YY, X, ABC[j], ABC[k]))) {
            cout << "Yes" << endl;
            return;
          }
        }
      }
    }
  }

  cout << "No" << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
