#include <bits/stdc++.h>
using namespace std;

template <class T>
int LIS(vector<T> a, bool is_strong = true) {
  const T INF = 1 << 30;  // to be set appropriately
  int n = (int)a.size();
  vector<T> dp(n, INF);
  for (int i = 0; i < n; ++i) {
    if (is_strong) {
      *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    } else {
      *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
  }

  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

void solve() {
  int N, M;
  cin >> N >> M;
  map<int, vector<int>> mp;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    mp[a].push_back(b);
  }
  vector<int> B;
  for (auto [key, v] : mp) {
    sort(v.begin(), v.end(), greater<int>());
    for (auto b : v) B.push_back(b);
  }

  auto ans = LIS(B);

  cout << ans << endl;
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
