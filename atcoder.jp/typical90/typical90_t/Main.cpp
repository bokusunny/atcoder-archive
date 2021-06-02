#include <bits/stdc++.h>
using namespace std;

long long my_pow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

int main() {
  long long a, b, c;
  cin >> a >> b >> c;

  if (my_pow(c, b) > a) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
