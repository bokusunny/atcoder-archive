#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int most_dist_node = 1;
  int most_dist = 0;
  for (int i = 2; i <= n; i++) {
    int dist;
    cout << "? " << 1 << " " << i << endl;
    cin >> dist;
    if (dist > most_dist) {
      most_dist = dist, most_dist_node = i;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == most_dist_node) continue;

    int dist;
    cout << "? " << most_dist_node << " " << i << endl;
    cin >> dist;
    if (dist > ans) ans = dist;
  }

  cout << "! " << ans << endl;

  return 0;
}
