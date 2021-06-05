#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n);
  for (int i = 0; i < n; i++) {
    vector<int> A(n);
    for (auto &a : A) cin >> a;
    cost.at(i) = A;
  }

  int m;
  cin >> m;
  vector<set<int>> kenen(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    kenen.at(x).insert(y);
    kenen.at(y).insert(x);
  }

  vector<int> a_order(n);
  for (int i = 0; i < n; i++) a_order.at(i) = i;

  const int INF = 1000000001;
  int ans = INF;
  do {
    bool is_possible = true;
    int tmp = 0;
    for (int ku = 0; ku < n; ku++) {
      int cur_a = a_order.at(ku);
      if (ku != n - 1) {
        int next_a = a_order.at(ku + 1);
        if (kenen.at(cur_a).count(next_a)) {
          is_possible = false;
          break;
        }
      }
      tmp += cost.at(cur_a).at(ku);
    }
    if (!is_possible) continue;
    if (tmp < ans) ans = tmp;
  } while (next_permutation(a_order.begin(), a_order.end()));

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
