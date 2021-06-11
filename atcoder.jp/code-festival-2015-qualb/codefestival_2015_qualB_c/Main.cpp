#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> A(n);
  for (auto &a : A) cin >> a;
  vector<int> B(m);
  for (auto &b : B) cin >> b;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int search_first = 0;
  for (auto b : B) {
    bool is_ok = false;
    for (int i = search_first; i < n; i++) {
      if (b > A.at(i)) continue;
      search_first = i + 1;
      is_ok = true;
      break;
    }
    if (!is_ok) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
