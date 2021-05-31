#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(2 * n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    A.emplace_back(b);
    A.emplace_back(a - b);
  }
  sort(A.begin(), A.end(), greater<int>());
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += A[i];
  }

  cout << ans << endl;

  return 0;
}
