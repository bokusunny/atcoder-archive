#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> s(n + 1);
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    s[i + 1] = s[i] + a;
  }

  map<long long, long long> m;
  for (auto i : s) m[i]++;

  long long ans = 0;
  for (auto [_, cnt] : m) ans += (cnt * (cnt - 1) / 2);

  cout << ans << endl;

  return 0;
}
