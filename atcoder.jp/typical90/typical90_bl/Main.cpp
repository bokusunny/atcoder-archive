#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> D(n - 1);
  long long prev;
  cin >> prev;
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    long long tmp;
    cin >> tmp;
    long long diff = tmp - prev;
    ans += abs(diff);
    D.at(i) = tmp - prev;
    prev = tmp;
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    long long v;
    cin >> v;
    l--, r--;

    if (l != 0) {
      long long prev = D.at(l - 1);
      long long &cur = D.at(l - 1);
      cur += v;
      ans += abs(cur);
      ans -= abs(prev);
    }
    if (r != n - 1) {
      long long prev = D.at(r);
      long long &cur = D.at(r);
      cur -= v;
      ans += abs(cur);
      ans -= abs(prev);
    }

    cout << ans << endl;
  }

  return 0;
}
