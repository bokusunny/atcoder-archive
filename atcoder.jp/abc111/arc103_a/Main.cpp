#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> m1, m2;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    s.insert(v);
    if (i % 2 == 0)
      m1[v]++;
    else
      m2[v]++;
  }

  if ((int)s.size() == 1) {
    cout << n / 2 << endl;
    return 0;
  }

  // v, cnt
  pair<int, int> m1_max = {0, 0}, m1_second = {0, 0}, m2_max = {0, 0}, m2_second = {0, 0};

  for (auto [v, cnt] : m1) {
    if (cnt > m1_max.second) {
      m1_second = m1_max;
      m1_max = {v, cnt};
    } else if (cnt > m1_second.second) {
      m1_second = {v, cnt};
    }
  }
  for (auto [v, cnt] : m2) {
    if (cnt > m2_max.second) {
      m2_second = m2_max;
      m2_max = {v, cnt};
    } else if (cnt > m2_second.second) {
      m2_second = {v, cnt};
    }
  }

  int ans = n - m1_max.second - m2_max.second;
  if (m1_max.first != m2_max.first) {
    cout << ans << endl;
    return 0;
  }

  int cost = min(m1_max.second - m1_second.second, m2_max.second - m2_second.second);
  cout << ans + cost << endl;

  return 0;
}
