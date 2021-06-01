#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int cap;
  if (n % 2 == 0) {
    cap = n / 2;
  } else {
    cap = n / 2 + 1;
  }

  if (cap >= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
