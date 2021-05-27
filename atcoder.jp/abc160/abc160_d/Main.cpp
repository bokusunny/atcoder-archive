#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;

  vector<int> dist(n, 0);

  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n; j++) {
      int not_use_xy = j - i;
      int use_xy = abs(i - x) + 1 + abs(j - y);
      dist[min(not_use_xy, use_xy)]++;
    }
  }

  for (int i = 1; i < n; i++) {
    cout << dist[i] << endl;
  }

  return 0;
}
