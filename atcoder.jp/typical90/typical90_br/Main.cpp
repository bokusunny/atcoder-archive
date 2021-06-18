#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> X;
  vector<int> Y;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    X.push_back(x), Y.push_back(y);
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int x, y;
  if (n % 2 == 0) {
    x = (X.at(n / 2) + X.at(n / 2 - 1)) / 2;
    y = (Y.at(n / 2) + Y.at(n / 2 - 1)) / 2;
  } else {
    x = X.at(n / 2);
    y = Y.at(n / 2);
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(x - X.at(i));
    ans += abs(y - Y.at(i));
  }

  cout << ans << endl;

  return 0;
}
