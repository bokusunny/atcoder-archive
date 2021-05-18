#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------
int main() {
  int n;
  cin >> n;

  const int table_size = pow(10, 5);
  vector<int> table(table_size, 0);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    table[a]++;
  }

  int ans = table[0] + table[1] + table[2];
  int tmp = ans;
  for (int i = 0; i < table_size - 3; i++) {
    tmp -= table[i];
    tmp += table[i + 3];
    if (ans < tmp) ans = tmp;
  }
  cout << ans << endl;
}
