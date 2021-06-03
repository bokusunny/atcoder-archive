#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  bool is_ok = true;
  for (int i = 1; i <= m; i++) {
    int c;
    cin >> c;
    if (n <= a) n += b;
    n -= c;
    if (n < 0) {
      cout << i << endl;
      return 0;
    }
  }

  if (is_ok) cout << "complete" << endl;

  return 0;
}
