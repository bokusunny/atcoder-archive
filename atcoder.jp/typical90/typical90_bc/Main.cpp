#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<long long> A(n);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    A[i] = a % p;
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int i2 = i + 1; i2 < n; i2++) {
      for (int i3 = i2 + 1; i3 < n; i3++) {
        for (int i4 = i3 + 1; i4 < n; i4++) {
          for (int i5 = i4 + 1; i5 < n; i5++) {
            if ((A[i]) * A[i2] % p * A[i3] % p * A[i4] % p * A[i5] % p == q) {
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}