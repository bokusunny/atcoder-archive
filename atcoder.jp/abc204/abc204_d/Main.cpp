#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> T(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    sum += t;
    T.at(i) = t;
  }

  int max_w = sum / 2;

  vector<vector<bool>> dp(n + 1, vector<bool>(max_w + 1, false));
  dp.at(0).at(0) = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= max_w; j++) {
      if (dp.at(i).at(j) == false) continue;

      dp.at(i + 1).at(j) = true;
      if (j + T.at(i) <= max_w) dp.at(i + 1).at(j + T.at(i)) = true;
    }
  }

  int max_bubunwa = 0;
  for (int i = 0; i <= max_w; i++) {
    if (dp.at(n).at(i) == true) max_bubunwa = i;
  }

  cout << sum - max_bubunwa << endl;

  return 0;
}
