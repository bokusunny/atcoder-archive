#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, Q;
  cin >> n >> Q;

  vector<long long> X(n);
  vector<long long> Y(n);
  const long long INF = 1LL << 60;
  long long max_x = -INF;
  long long max_y = -INF;
  long long min_x = INF;
  long long min_y = INF;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;

    long long x45 = x + y, y45 = x - y;
    X.at(i) = x45, Y.at(i) = y45;

    max_x = max(x45, max_x);
    max_y = max(y45, max_y);
    min_x = min(x45, min_x);
    min_y = min(y45, min_y);
  }

  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;
    q--;

    long long ans = 0;
    long long x = X.at(q), y = Y.at(q);
    ans = max(ans, max_x - x);
    ans = max(ans, x - min_x);
    ans = max(ans, max_y - y);
    ans = max(ans, y - min_y);
    cout << ans << endl;
  }

  return 0;
}
