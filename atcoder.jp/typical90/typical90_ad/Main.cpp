#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> cnt_table(n + 1, 0);

  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (cnt_table.at(i) == 0) {
      for (int j = i; j <= n; j += i) cnt_table.at(j)++;
    }

    if (cnt_table.at(i) >= k) ans++;
  }

  cout << ans << endl;

  return 0;
}
