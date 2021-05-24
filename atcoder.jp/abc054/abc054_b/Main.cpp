#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid_n(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    string A;
    cin >> A;

    for (int j = 0; j < n; j++) {
      grid_n[i][j] = A[j];
    }
  }
  vector<vector<char>> grid_m(m, vector<char>(m));
  for (int i = 0; i < m; i++) {
    string B;
    cin >> B;

    for (int j = 0; j < m; j++) {
      grid_m[i][j] = B[j];
    }
  }

  for (int ni = 0; ni < n; ni++) {
    for (int nj = 0; nj < n; nj++) {
      bool is_fail = false;
      for (int mi = 0; mi < m; mi++) {
        for (int mj = 0; mj < m; mj++) {
          if (ni + mi == n || nj + mj == n ||
              grid_n[ni + mi][nj + mj] != grid_m[mi][mj]) {
            is_fail = true;
            break;
          }
        }
        if (is_fail) break;
      }
      if (!is_fail) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
