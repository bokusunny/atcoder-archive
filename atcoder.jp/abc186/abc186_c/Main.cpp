#include <bits/stdc++.h>
using namespace std;

auto to_base(long long x, int to_base) {
  if (x == 0LL) return 0LL;

  string res = "";
  while (x > 0) {
    res = to_string(x % to_base) + res;
    x /= to_base;
  }

  return stoll(res);
}

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s1 = to_string(i);
    string s2 = to_string(to_base(i, 8));
    if (count(s1.begin(), s1.end(), '7') || count(s2.begin(), s2.end(), '7')) continue;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
