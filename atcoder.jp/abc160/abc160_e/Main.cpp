#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> P(a);
  for (auto &p : P) cin >> p;
  vector<int> Q(b);
  for (auto &q : Q) cin >> q;
  vector<int> R(c);
  for (auto &r : R) cin >> r;
  sort(P.begin(), P.end(), greater<int>());
  sort(Q.begin(), Q.end(), greater<int>());

  priority_queue<int, vector<int>, greater<int>> h;

  for (int i = 0; i < x; i++) h.push(P[i]);
  for (int i = 0; i < y; i++) h.push(Q[i]);
  for (int i = 0; i < c; i++) {
    h.push(R[i]);
    h.pop();
  }

  long long ans = 0;
  for (int i = 0; i < x + y; i++) {
    ans += h.top();
    h.pop();
  }

  cout << ans << endl;

  return 0;
}
