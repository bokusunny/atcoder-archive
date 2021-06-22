#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<vector<int>> Q;
int ans = 0;

void dfs(vector<int> &v) {
  int size = (int)v.size();
  int last = size == 0 ? 1 : v.at(size - 1);

  if (size == n) {
    int tmp = 0;
    for (auto q : Q) {
      int a = q.at(0), b = q.at(1), c = q.at(2), d = q.at(3);
      if (v.at(b - 1) - v.at(a - 1) == c) tmp += d;
    }
    ans = max(ans, tmp);
  } else {
    for (int i = last; i <= m; i++) {
      v.push_back(i);
      dfs(v);
    }
  }

  v.pop_back();
}

int main() {
  cin >> n >> m >> q;

  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    Q.push_back({a, b, c, d});
  }

  vector<int> v;
  dfs(v);

  cout << ans << endl;

  return 0;
}
