#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    A.at(i) = a;
  }

  long long sum = 0;
  for (int i = 1; i <= n + 1; i++) {
    sum += abs(A.at(i) - A.at(i - 1));
  }

  for (int i = 1; i <= n; i++) {
    long long ans = sum;
    ans -= abs(A.at(i) - A.at(i - 1));
    ans -= abs(A.at(i + 1) - A.at(i));
    ans += abs(A.at(i + 1) - A.at(i - 1));
    cout << ans << endl;
  }

  return 0;
}
