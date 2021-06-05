#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<set<int>> v(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v.at(a).insert(b);
    v.at(b).insert(a);
  }

  for (auto to : v.at(0)) {
    if (v.at(to).count(n - 1)) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
