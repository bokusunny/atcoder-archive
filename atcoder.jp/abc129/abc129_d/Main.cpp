#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      grid.at(i).at(j) = c == '.' ? 1 : 0;
    }
  }

  vector<vector<int>> horizontal_cnt(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    vector<int> tmp1(w, 0);
    int streak = 0;
    for (int j = 0; j < w; j++) {
      if (grid.at(i).at(j) == 1) {
        streak++;
        tmp1.at(j) = streak;
      } else {
        streak = 0;
      }
    }

    streak = 0;
    vector<int> tmp2(w, 0);
    for (int j = w - 1; j >= 0; j--) {
      if (grid.at(i).at(j) == 1) {
        streak++;
        tmp2.at(j) = streak;
      } else {
        streak = 0;
      }
    }

    for (int j = 0; j < w; j++) {
      horizontal_cnt.at(i).at(j) = tmp1.at(j) + tmp2.at(j) - 1;
    }
  }
  vector<vector<int>> vertical_cnt(h, vector<int>(w));
  for (int i = 0; i < w; i++) {
    vector<int> tmp1(h, 0);
    int streak = 0;
    for (int j = 0; j < h; j++) {
      if (grid.at(j).at(i) == 1) {
        streak++;
        tmp1.at(j) = streak;
      } else {
        streak = 0;
      }
    }

    streak = 0;
    vector<int> tmp2(h, 0);
    for (int j = h - 1; j >= 0; j--) {
      if (grid.at(j).at(i) == 1) {
        streak++;
        tmp2.at(j) = streak;
      } else {
        streak = 0;
      }
    }

    for (int j = 0; j < h; j++) {
      vertical_cnt.at(j).at(i) = tmp1.at(j) + tmp2.at(j) - 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int tmp = vertical_cnt.at(i).at(j) + horizontal_cnt.at(i).at(j) - 1;
      if (ans < tmp) ans = tmp;
    }
  }

  cout << ans << endl;

  return 0;
}
