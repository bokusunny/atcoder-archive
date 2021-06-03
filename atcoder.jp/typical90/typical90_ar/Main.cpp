#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> A(n);
  for (auto &a : A) cin >> a;
  int shift_cnt = 0;

  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    x--, y--;
    if (x - shift_cnt < 0) x += n;
    if (y - shift_cnt < 0) y += n;

    if (t == 1) {
      auto &x_ref = A.at(x - shift_cnt);
      auto &y_ref = A.at(y - shift_cnt);
      int x_val = A.at(x - shift_cnt);
      int y_val = A.at(y - shift_cnt);
      x_ref = y_val;
      y_ref = x_val;
    } else if (t == 2) {
      shift_cnt++;
      if (shift_cnt == n) shift_cnt = 0;
    } else {
      cout << A.at(x - shift_cnt) << endl;
    }
  }

  return 0;
}
