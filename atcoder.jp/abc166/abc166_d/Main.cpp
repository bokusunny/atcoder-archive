#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long X;
  cin >> X;
  for (int A = -1000; A < 1000; A++) {
    for (int B = -1000; B < 1000; B++) {
      long long a = 1, b = 1;
      for (int i = 0; i < 5; i++) a *= A;
      for (int i = 0; i < 5; i++) b *= B;
      if (a - b == X) {
        cout << A << " " << B << endl;
        return;
      }
    }
  }
}

int main() {
  solve();

  return 0;
}
