#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  long long g = gcd(gcd(a, b), c);

  cout << a / g + b / g + c / g - 3 << endl;

  return 0;
}
