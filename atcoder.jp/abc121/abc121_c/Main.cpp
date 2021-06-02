#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<long long, long long>> list;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;

    list.emplace_back(make_pair(a, b));
  }
  sort(list.begin(), list.end(),
       [](pair<long long, long long> p1, pair<long long, long long> p2) {
         return p1.first < p2.first;
       });

  long long ans = 0;
  for (auto [p, num] : list) {
    if (m < num) num = m;
    ans += p * num;
    m -= num;
    if (m == 0) break;
  }

  cout << ans << endl;

  return 0;
}
