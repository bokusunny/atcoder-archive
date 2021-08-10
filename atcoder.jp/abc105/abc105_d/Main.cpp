#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;
  map<int, long long> mp;
  mp[0]++;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    sum += a;
    sum %= M;
    mp[sum]++;
  }
  long long ans = 0;
  for (auto [amari, cnt] : mp) {
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
