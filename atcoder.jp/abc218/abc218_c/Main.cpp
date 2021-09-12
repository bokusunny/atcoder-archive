#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<string> S(N), T(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < N; i++) cin >> T[i];

  int cnts = 0, cntt = 0;
  for (int i = 0; i < N; i++) {
    cnts += count(S[i].begin(), S[i].end(), '#');
    cntt += count(T[i].begin(), T[i].end(), '#');
  }

  if (cnts != cntt) {
    cout << "No" << endl;
    return;
  }

  auto rotate = [&](vector<string> &Mat) {
    string s(N, '.');
    vector<string> res(N, s);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        res[N - 1 - j][i] = Mat[i][j];
      }
    }
    return res;
  };

  auto get_top_left = [&](vector<string> &Mat, int &y, int &x) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (Mat[i][j] == '#') {
          y = i;
          x = j;
          return;
        }
      }
    }
  };

  auto is_same = [&](vector<string> &Mat) {
    int sy, sx, ty, tx;
    get_top_left(Mat, sy, sx);
    get_top_left(T, ty, tx);
    int dy = ty - sy;
    int dx = tx - sx;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int ii = i + dy;
        int jj = j + dx;
        if (0 <= ii && ii < N && 0 <= jj && jj < N) {
          if (Mat[i][j] != T[ii][jj]) return false;
        } else {
          if (Mat[i][j] == '#') return false;
        }
      }
    }
    return true;
  };

  for (int i = 0; i < 4; i++) {
    if (is_same(S)) {
      cout << "Yes" << endl;
      return;
    }
    S = rotate(S);
  }

  cout << "No" << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
