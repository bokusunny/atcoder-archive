#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b;
    cin >> b;
    int j = lower_bound(A.begin(), A.end(), b) - A.begin();

    if (j == 0) {
      cout << A[j] - b << endl;
    } else if (j == n) {
      cout << b - A[j - 1] << endl;
    } else {
      cout << min(A[j] - b, b - A[j - 1]) << endl;
    }
  }

  return 0;
}