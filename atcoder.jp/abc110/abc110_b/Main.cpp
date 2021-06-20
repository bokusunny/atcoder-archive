#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int max_x = -1000, min_y = 1000;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    max_x = max(max_x, x);
  }
  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;
    min_y = min(y, min_y);
  }

  for (int i = x + 1; i <= y; i++) {
    if (max_x < i && i <= min_y) {
      cout << "No War" << endl;
      return 0;
    }
  }

  cout << "War" << endl;

  return 0;
}
