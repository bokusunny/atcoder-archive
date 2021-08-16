#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;

  if (N & 1) {
    for (int i = 1; i <= M; i++) {
      cout << i << " " << (N - i + 1) << endl;
    }
  } else {
    int l = 1, r = N;
    set<int> seen;
    for (int i = 1; i <= M; i++) {
      auto diff1 = r - l, diff2 = l + N - r;
      if (seen.count(diff1) || diff1 == diff2) {
        r--;
        diff1--;
        diff2++;
      }
      assert(l < r);
      cout << l << " " << r << endl;
      seen.insert(diff1);
      seen.insert(diff2);
      l++;
      r--;
    }
  }
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
