#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  // 長さx以上のようかんk+1個以上に分割できるか？
  auto is_ok = [&](int x) {
    int cnt = 0;
    int last_cut_pos = 0;
    for (auto a : A) {
      if (a - last_cut_pos >= x) {
        cnt++;
        last_cut_pos = a;
      }
    }
    if (l - last_cut_pos >= x) cnt++;

    if (cnt >= k + 1) {
      return true;
    } else {
      return false;
    }
  };

  int ok = -1, ng = 1000000001;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (is_ok(mid))
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;

  return 0;
}
