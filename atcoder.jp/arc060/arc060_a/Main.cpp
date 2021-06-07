#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;

  vector<int> X(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x -= a;
    X.at(i) = x;
  }

  // -2500~2500
  vector<vector<long long>> dp(n + 1, vector<long long>(5001, 0));
  dp.at(0).at(2500) = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5001; j++) {
      if (dp.at(i).at(j) == 0) continue;
      dp.at(i + 1).at(j) += dp.at(i).at(j);
      dp.at(i + 1).at(j + X.at(i)) += dp.at(i).at(j);
    }
  }

  // 一枚も選ばないパターンを除く
  cout << dp.at(n).at(2500) - 1 << endl;

  return 0;
}
