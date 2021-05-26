#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<int> A(n);
  for (int &a : A) cin >> a;

  int l = 0, r = 0;
  long long ans = 0, tmp_sum = A[0];

  while (l < n) {
    if (tmp_sum >= k) {
      ans += n - r;
      if (l == r) {
        r++;
        tmp_sum += A[r];
      }
      tmp_sum -= A[l];
      l++;
    } else {
      if (r == n - 1) {
        break;
      }
      r++;
      tmp_sum += A[r];
    }
  }

  cout << ans << endl;

  return 0;
}
