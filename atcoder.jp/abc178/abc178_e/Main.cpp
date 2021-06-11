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
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  const int INF = 1000000001;
  int max_x = -INF;
  int max_y = -INF;
  int min_x = INF;
  int min_y = INF;

  for (int i = 0; i < n; i++) {
    int tmp_x, tmp_y;
    cin >> tmp_x >> tmp_y;

    int x = tmp_x + tmp_y;
    int y = tmp_x - tmp_y;

    chmax(max_x, x);
    chmax(max_y, y);
    chmin(min_x, x);
    chmin(min_y, y);
  }

  cout << max(max_x - min_x, max_y - min_y) << endl;

  return 0;
}
