#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long H;
  cin >> H;

  function<long long(long long)> f = [&](long long h) {
    if (h == 1) return 1LL;
    return 2LL * f(h / 2) + 1;
  };

  cout << f(H) << endl;
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
