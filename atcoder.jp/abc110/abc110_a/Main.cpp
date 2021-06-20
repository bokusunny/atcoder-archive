#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = max(10 * a + b + c, a + 10 * b + c);
  cout << max(ans, c * 10 + a + b) << endl;

  return 0;
}
