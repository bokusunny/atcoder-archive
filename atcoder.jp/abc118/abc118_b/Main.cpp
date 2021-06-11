#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> vec(m, true);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    set<int> S;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;

      S.insert(a - 1);
    }

    for (int i = 0; i < m; i++) {
      if (!S.count(i)) vec.at(i) = false;
    }
  }

  int cnt = 0;
  for (auto b : vec) {
    if (b) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
