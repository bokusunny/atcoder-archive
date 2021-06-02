#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> A(m);
  for (auto &a : A) cin >> a;
  reverse(A.begin(), A.end());

  vector<int> order;

  set<int> S;
  for (int i = 1; i <= n; i++) S.insert(i);
  for (auto a : A) {
    if (S.count(a) == 0) continue;

    order.emplace_back(a);
    S.erase(a);
  }

  for (auto o : order) cout << o << endl;
  for (auto s : S) cout << s << endl;

  return 0;
}
