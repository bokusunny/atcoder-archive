#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<long long>> nCk_table(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; i++) {
    nCk_table[i][0] = 1;
    nCk_table[i][i] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      nCk_table[i][j] = nCk_table[i - 1][j - 1] + nCk_table[i - 1][j];
    }
  }

  cout << nCk_table[n - 1][11] << endl;

  return 0;
}
