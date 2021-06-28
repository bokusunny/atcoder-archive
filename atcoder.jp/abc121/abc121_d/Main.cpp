#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
  if (x % 4 == 1) {
    return 1;
  } else if (x % 4 == 3) {
    return 0;
  } else if (x % 4 == 0) {
    return x;
  } else {
    return 1 ^ x;
  }
}

int main() {
  long long A, B;
  cin >> A >> B;

  if (A == 0) {
    cout << f(B) << endl;
  } else {
    cout << (f(B) ^ f(A - 1)) << endl;
  }

  return 0;
}
