#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> iP(m);
  vector<vector<pair<int, int>>> P_cities(n + 1);

  for (int i = 0; i < m; i++) {
    int p, y;
    cin >> p >> y;
    iP.at(i) = p;
    P_cities.at(p).emplace_back(y, i);
  }

  vector<pair<int, int>> ans(m);
  for (int p = 1; p <= n; p++) {
    auto vp = P_cities.at(p);
    if (vp.empty()) continue;
    sort(vp.begin(), vp.end());
    for (int x = 1; x <= (int)vp.size(); x++) {
      auto [y, i] = vp.at(x - 1);
      ans.at(i).first = p;
      ans.at(i).second = x;
    }
  }

  for (auto [p, x] : ans) printf("%06d%06d\n", p, x);

  return 0;
}
