#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w, 0));
  vector<int> r(h, 0);
  vector<int> c(w, 0);
  for (int i = 0; i < h; i++) {
    int r_tmp = 0;
    for (int j = 0; j < w; j++) {
      int a;
      cin >> a;
      grid[i][j] = a;
      r_tmp += a;
    }
    r[i] = r_tmp;
  }

  for (int j = 0; j < w; j++) {
    int c_tmp = 0;
    for (int i = 0; i < h; i++) {
      c_tmp += grid[i][j];
    }
    c[j] = c_tmp;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << r[i] + c[j] - grid[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
