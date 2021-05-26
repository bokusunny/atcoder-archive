#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prime_factorize(int N) {
  vector<pair<int, int>> res;
  for (int i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    int ex = 0;
    while (N % i == 0) {
      ex++;
      N /= i;
    }
    res.push_back({i, ex});
  }

  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> ex(n + 1);

  for (int i = 2; i <= n; i++) {
    auto pf = prime_factorize(i);
    for (auto p : pf) ex[p.first] += p.second;
  }

  int over_two = 0, over_four = 0, over_fourteen = 0, over_twentyfour = 0,
      over_seventyfour = 0;
  for (auto e : ex) {
    if (e >= 2) over_two++;
    if (e >= 4) over_four++;
    if (e >= 14) over_fourteen++;
    if (e >= 24) over_twentyfour++;
    if (e >= 74) over_seventyfour++;
  }

  int ans = 0;
  if (over_seventyfour) ans += over_seventyfour;
  if (over_twentyfour) ans += (over_twentyfour * (over_two - 1));
  if (over_fourteen) ans += (over_fourteen * (over_four - 1));
  if (over_four >= 2 && over_two >= 3) {
    ans += (over_four * (over_four - 1) / 2 * (over_two - 2));
  }

  cout << ans << endl;

  return 0;
}
