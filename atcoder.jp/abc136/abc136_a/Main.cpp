#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = b + c <= a ? 0 : b + c - a;
  cout << ans << endl;

  return 0;
}
