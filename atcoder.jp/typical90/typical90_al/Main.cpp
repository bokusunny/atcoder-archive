#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  long long g = gcd(a, b);
  long long da = a / g;
  long long db = b / g;

  if (db > 1000000000000000000LL / a) {
    cout << "Large" << endl;
  } else {
    cout << g * da * db << endl;
  }

  return 0;
}
