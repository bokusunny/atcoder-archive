#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> s(n + 2, vector<int>(n + 2, 0));

  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    a--;
    b--;

    s[a][b]++;
    s[a][b + 1]--;
    s[a + x + 1][b]--;
    s[a + x + 1][b + x + 2]++;
    s[a + x + 2][b + 1]++;
    s[a + x + 2][b + x + 2]--;
  }

  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 1; j++) {
      s[i][j + 1] += s[i][j];
    }
  }
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 1; j++) {
      s[j + 1][i] += s[j][i];
    }
  }
  // 固定されているのはa-b
  for (int i = 0; i < n + 2; i++) {
    // 固定されているのはb
    for (int j = 0; j < n + 1 - i; j++) {
      s[i + j + 1][j + 1] += s[i + j][j];
    }
  }

  long long ans = 0;
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) {
      if (s[i][j] != 0) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
