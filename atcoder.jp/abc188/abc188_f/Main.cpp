#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long X, Y;
  cin >> X >> Y;

  map<long long, long long> Memo;
  function<long long(long long)> dfs = [&](long long y) {
    if (Memo.count(y)) return Memo[y];

    long long res = abs(X - y);
    if (y == 1) return Memo[y] = res;

    if (y & 1) {
      res = min(res, dfs((y + 1) / 2) + 2);
      res = min(res, dfs((y - 1) / 2) + 2);
    } else {
      res = min(res, dfs(y / 2) + 1);
    }

    return Memo[y] = res;
  };

  cout << dfs(Y) << endl;
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
