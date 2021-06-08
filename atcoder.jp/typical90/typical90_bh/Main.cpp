#include <bits/stdc++.h>
using namespace std;

template <class T>
auto LIS(vector<T> a) {
  const T INF = 1 << 30;
  int n = (int)a.size();
  vector<int> table(n, 0);
  vector<T> dp(n, INF);
  int dp_elm_cnt = 0;
  for (int i = 0; i < n; ++i) {
    auto itr = lower_bound(dp.begin(), dp.end(), a[i]);
    if (itr - dp.begin() >= dp_elm_cnt) dp_elm_cnt++;
    table.at(i) = dp_elm_cnt;

    *itr = a[i];
  }

  return table;
}

int main() {
  int n;
  cin >> n;
  vector<int> A1(n);
  for (auto &a : A1) cin >> a;
  vector<int> A2(n);
  A2 = A1;
  reverse(A2.begin(), A2.end());

  auto A1_table = LIS(A1);
  auto A2_table = LIS(A2);

  int ans = 1;
  for (int i = 0; i < n; i++) {
    int tmp = A1_table.at(i) + A2_table.at(n - 1 - i) - 1;
    ans = max(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
