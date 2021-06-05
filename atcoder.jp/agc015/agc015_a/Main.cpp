#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;

  if (a > b || (n == 1 && a != b)) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1 || n == 2 || a == b) {
    cout << 1 << endl;
    return 0;
  }

  cout << ((n - 1) * b + a) - ((n - 1) * a + b - 1) << endl;

  return 0;
}
