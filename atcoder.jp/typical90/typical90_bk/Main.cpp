#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int a;
      cin >> a;
      grid.at(i).at(j) = a;
    }
  }

  int ans = 0;
  for (int i = 0; i < 1 << h; i++) {
    if (i == 0) continue;
    vector<int> hs;
    for (int j = 0; j < h; j++) {
      if (i >> j & 1) hs.push_back(j);
    }
    map<int, int> M;
    for (int j = 0; j < w; j++) {
      int tmp = grid.at(hs.at(0)).at(j);
      bool is_valid = true;
      for (int k = 1; k < (int)hs.size(); k++) {
        if (grid.at(hs.at(k)).at(j) != tmp) {
          is_valid = false;
          break;
        }
      }
      if (is_valid) M[tmp]++;
    }
    for (auto [key, val] : M) chmax(ans, (int)hs.size() * val);
  }

  cout << ans << endl;

  return 0;
}
