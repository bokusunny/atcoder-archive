#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// --------------------------------------------------------
int main() {
  int m,n,k;
  cin >> m >> n >> k;

  vector<vector<int>> grid(m, vector<int>(n, 0));
  rep(i,m) {
    string s;
    cin >> s;
    rep(j,n) {
      if (s.at(j) == 'O') grid[i][j] = 1;
      if (s.at(j) == 'I') grid[i][j] = 2;
    }
  }

  vector<vector<vector<int>>> s(m+1, vector<vector<int>>(n+1, vector<int>(3, 0)));
  rep2(y, 1, m+1) {
    rep2(x, 1, n+1) {
      int key_to_add = grid.at(y-1).at(x-1);
      rep(key, 3) {
        s[y][x][key] = s[y-1][x][key] + s[y][x-1][key] - s[y-1][x-1][key];
        if (key == key_to_add) s[y][x][key]++;
      }
    }
  }

  rep(_, k) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    rep(key, 3) {
      int ans = s[c][d][key] - s[c][b-1][key] - s[a-1][d][key] + s[a-1][b-1][key];
      cout << ans;
      if (key == 2) cout << endl;
      else cout << " ";
    }
  }
}
