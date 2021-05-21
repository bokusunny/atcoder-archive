#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  cin >> n;

  vector<vector<int>> param(n, vector<int>(5));
  for (auto &a : param)
    for (int &i : a) cin >> i;

  int ok = -1, ng = pow(10, 9) + 1;
  auto is_ok = [&](int x) {
    set<int> s;
    for (auto a : param) {
      int bit = 0;
      for (int i : a) {
        bit <<= 1;
        bit |= i >= x;
      }
      s.insert(bit);
    }

    for (int x : s)
      for (int y : s)
        for (int z : s)
          if ((x | y | z) == 31) return 1;

    return 0;
  };

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
