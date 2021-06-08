#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  vector<int> B(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    A.at(i) = a;
    B.at(i) = b;
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  dp.at(0).at(0) = true;

  for (int i = 0; i < n; i++) {
    int a = A.at(i), b = B.at(i);
    for (int j = 0; j < s + 1; j++) {
      if (dp.at(i).at(j) == false) continue;
      if (j + a <= s) dp.at(i + 1).at(j + a) = true;
      if (j + b <= s) dp.at(i + 1).at(j + b) = true;
    }
  }

  if (dp.at(n).at(s) == false) {
    cout << "Impossible" << endl;
    return 0;
  }

  string ans = "";
  for (int i = n; i >= 1; i--) {
    int a = A.at(i - 1), b = B.at(i - 1);
    if (s - a >= 0 && dp.at(i - 1).at(s - a) == true) {
      ans = 'A' + ans;
      s -= a;
    } else if (s - b >= 0 && dp.at(i - 1).at(s - b) == true) {
      ans = 'B' + ans;
      s -= b;
    }
  }

  cout << ans << endl;

  return 0;
}
