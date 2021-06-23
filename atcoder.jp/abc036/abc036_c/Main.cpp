#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  auto v = A;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for (auto &a : A) {
    a = lower_bound(v.begin(), v.end(), a) - v.begin();
  }

  for (auto a : A) cout << a << endl;

  return 0;
}
