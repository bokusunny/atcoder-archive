#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
    A.at(i) = a;
  }
  sort(A.begin(), A.end());

  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    auto a = A.at(i);
    if (a % 10 != 0) {
      cout << sum - a << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;

  return 0;
}
