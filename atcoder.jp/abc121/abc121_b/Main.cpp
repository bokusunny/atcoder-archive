#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> B(m);
  for (auto &b : B) cin >> b;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int total = 0;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      total += a * B[j];
    }
    total += c;
    if (total > 0) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
