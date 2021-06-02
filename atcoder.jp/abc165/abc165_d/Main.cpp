#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, n;
  cin >> a >> b >> n;

  if (n >= b) {
    cout << a * (b - 1) / b << endl;
  } else {
    cout << a * n / b << endl;
  }

  return 0;
}
