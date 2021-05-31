#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (auto &a : A) cin >> a;
  vector<int> B(n);
  for (auto &b : B) cin >> b;

  long long diff = 0;
  for (int i = 0; i < n; i++) {
    int a = A[i], b = B[i];
    diff += abs(a - b);
  }

  if (diff <= k && (k - diff) % 2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
