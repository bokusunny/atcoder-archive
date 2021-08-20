#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  sort(L.begin(), L.end());

  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      auto a = L[i], b = L[j];
      auto upper = a + b;
      auto lower = b - a;
      cnt += lower_bound(L.begin(), L.end(), upper) - L.begin() - (upper_bound(L.begin(), L.end(), lower) - L.begin());
      cnt--;
      if (2 * a > b) cnt--;
    }
  }

  assert(cnt % 3 == 0);
  cout << cnt / 3 << endl;
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
