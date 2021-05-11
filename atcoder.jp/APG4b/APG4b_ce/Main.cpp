#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<char>> vec(n, vector<char>(n, '-'));

  rep(_, m) {
    int i,j;
    cin >> i >> j;
    i--;
    j--;
    vec[i][j] = 'o';
    vec[j][i] = 'x';
  }

  rep(i, n) {
    rep(j, n) {
      cout << vec[i][j];
      if (j == n-1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
}

