#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, C;
  cin >> n >> C;

  map<int, long long> dic;
  for (int i = 0; i < n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    dic[a] += c;
    dic[b + 1] -= c;
  }

  long long ans = 0, fee = 0, t = 0;
  for (auto [key, val] : dic) {
    ans += (min(C, fee) * (key - t));
    fee += val;
    t = key;
  }

  cout << ans << endl;

  return 0;
}
